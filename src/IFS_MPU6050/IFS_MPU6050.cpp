#include "IFS_MPU6050.h"

namespace IcarusLib{
	

	IFS_MPU6050::IFS_MPU6050()
	{
		gyroAccel = new MPU6050;
	}

	//improve the destructor
	IFS_MPU6050::~IFS_MPU6050()
	{
		delete gyroAccel;
	}


	void IFS_MPU6050::Initialize(unsigned pinSDA, unsigned pinSCL)
	{
		SDA = pinSDA;
		SCL=pinSCL;
		setupMPU6050();

	}


	bool IFS_MPU6050::setupMPU6050(uint8_t &mpuIntStatus, uint8_t &devStatus, uint16_t &packetSize; )
	{
		gyroAccel->initialize();
		
		if(gyroAccel->testConnection() == false)
			{
				return false;
			}

			//it missed set up the offser
		if(gyroAccel->dmpInitialize()==0)
		{
		
			gyroAccel->setDMPEnabled(true);

			//DUVIDA DE COMO FAZER ESSE PASSO e FALTOU SETAR OS OFFSETS
			attachInterrupt(0, IFS_MPU6050::dmpDataReady(), RISING);
        	mpuIntStatus = gyroAccel->getIntStatus();

        mpuIntStatus = gyroAccel->getIntStatus();

        // set our DMP Ready flag so the main loop() function knows it's okay to use it
        //Serial.println(F("DMP ready! Waiting for first interrupt..."));
        dmpReady = true;

        // get expected DMP packet size for later comparison
        packetSize = gyroAccel->dmpGetFIFOPacketSize();

		}
		else{
			return false;
		}

		return true;

	}


	void IFS_MPU6050::IFS_dmpDataReady(volatile bool &mpuInterrupt){
			mpuInterrupt = true;
	}




}