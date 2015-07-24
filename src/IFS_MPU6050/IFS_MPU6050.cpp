#include "IFS_MPU6050.h"

namespace IcarusLib{


IFS_MPU6050::IFS_MPU6050(){
    gyroAccel = new MPU6050;
}

IFS_MPU6050::~IFS_MPU6050(){
    delete gyroAccel;
}


void IFS_MPU6050::Initialize(unsigned pinSDA, unsigned pinSCL){
    SDA = pinSDA;
    SCL=pinSCL;
    setupMPU6050();
}


bool IFS_MPU6050::setupMPU6050(uint8_t &mpuIntStatus, uint8_t &devStatus,
                                   uint16_t &packetSize, bool &dmpReady, 
                                   volatile bool &mpuInterrupt )
{
    gyroAccel->initialize();

    if(gyroAccel->testConnection() == false){
        return false;
    }

    //it missed set up the offser
    if(gyroAccel->dmpInitialize()==0){
        gyroAccel->setDMPEnabled(true);

        //DUVIDA DE COMO FAZER ESSE PASSO e FALTOU SETAR OS OFFSETS
        attachInterrupt(0, &IFS_MPU6050::dmpDataReady(mpuInterrupt), RISING);
        mpuIntStatus = gyroAccel->getIntStatus();
       
        // set our DMP Ready flag so the main loop() function knows it's okay to use it
        //Serial.println(F("DMP ready! Waiting for first interrupt..."));
        dmpReady = true;

        // get expected DMP packet size for later comparison
        packetSize = gyroAccel->dmpGetFIFOPacketSize();
    
    } else {
        return false;
    }

    return true;

}


void IFS_MPU6050::IFS_dmpDataReady(volatile bool &mpuInterrupt){
    mpuInterrupt = true;
}



std::vector<double> IFS_MPU6050::readGyro() {
    mpuInterrupt= false;
    mpuIntStatus = gyroAccel->getIntStatus();
    fifoCount = gyroAccel->getFIFOCount();

    if ((mpuIntStatus & 0x10) || fifoCount == 1024) {
        mpu->resetFIFO();
        Serial.println(F("FIFO overflow!"));


    } else if (mpuIntStatus & 0x02) {
        // wait for correct available data length, should be a VERY short wait
        while (fifoCount < packetSize) fifoCount = gyroAccel->getFIFOCount();

        // read a packet from FIFO
        gyroAccel->getFIFOBytes(fifoBuffer, packetSize);
            
        
        // (this lets us immediately read more without waiting for an interrupt)
        fifoCount -= packetSize;

        #ifdef OUTPUT_READABLE_UATERNION
            // display uaternion values in easy matrix form: w x y z
            gyroAccel->dmpGetuaternion(&, fifoBuffer);
            Serial.print("uat\t");
            Serial.print(.w);
            Serial.print("\t");
            Serial.print(.x);
            Serial.print("\t");
            Serial.print(.y);
            Serial.print("\t");
            Serial.println(.z);
        #endif

        #ifdef OUTPUT_READABLE_EULER
            // display Euler angles in degrees
            gyroAccel->dmpGetuaternion(&, fifoBuffer);
            gyroAccel->dmpGetEuler(euler, &);
            Serial.print("euler\t");
            Serial.print(euler[0] * 180/M_PI);
            Serial.print("\t");
            Serial.print(euler[1] * 180/M_PI);
            Serial.print("\t");
            Serial.println(euler[2] * 180/M_PI);
        #endif

        #ifdef OUTPUT_READABLE_YAWPITCHROLL
            // display Euler angles in degrees
            gyroAccel->dmpGetuaternion(&, fifoBuffer);
            gyroAccel->dmpGetGravity(&gravity, &);
            gyroAccel->dmpGetYawPitchRoll(ypr, &, &gravity);
            Serial.print("ypr\t");
            Serial.print(ypr[0] * 180/M_PI);
            Serial.print("\t");
            Serial.print(ypr[1] * 180/M_PI);
            Serial.print("\t");
            Serial.println(ypr[2] * 180/M_PI);
        #endif

        #ifdef OUTPUT_READABLE_REALACCEL
            // display real acceleration, adjusted to remove gravity
            gyroAccel->dmpGetuaternion(&, fifoBuffer);
            gyroAccel->dmpGetAccel(&aa, fifoBuffer);
            gyroAccel->dmpGetGravity(&gravity, &);
            gyroAccel->dmpGetLinearAccel(&aaReal, &aa, &gravity);
            Serial.print("areal\t");
            Serial.print(aaReal.x);
            Serial.print("\t");
            Serial.print(aaReal.y);
            Serial.print("\t");
            Serial.println(aaReal.z);
        #endif

        #ifdef OUTPUT_READABLE_WORLDACCEL
            // display initial world-frame acceleration, adjusted to remove gravity
            // and rotated based on known orientation from uaternion
            gyroAccel->dmpGetuaternion(&, fifoBuffer);
            gyroAccel->dmpGetAccel(&aa, fifoBuffer);
            gyroAccel->dmpGetGravity(&gravity, &);
            gyroAccel->dmpGetLinearAccel(&aaReal, &aa, &gravity);
            gyroAccel->dmpGetLinearAccelInWorld(&aaWorld, &aaReal, &);
            Serial.print("aworld\t");
            Serial.print(aaWorld.x);
            Serial.print("\t");
            Serial.print(aaWorld.y);
            Serial.print("\t");
            Serial.println(aaWorld.z);
        #endif
        
        #ifdef OUTPUT_TEAPOT
            // display uaternion values in InvenSense Teapot demo format:
            teapotPacket[2] = fifoBuffer[0];
            teapotPacket[3] = fifoBuffer[1];
            teapotPacket[4] = fifoBuffer[4];
            teapotPacket[5] = fifoBuffer[5];
            teapotPacket[6] = fifoBuffer[8];
            teapotPacket[7] = fifoBuffer[9];
            teapotPacket[8] = fifoBuffer[12];
            teapotPacket[9] = fifoBuffer[13];
            Serial.write(teapotPacket, 14);
            teapotPacket[11]++; // packetCount, loops at 0xFF on purpose
        #endif

    // blink LED to indicate activity
    blinkState = !blinkState;
    digitalWrite(LED_PIN, blinkState);

    }
}