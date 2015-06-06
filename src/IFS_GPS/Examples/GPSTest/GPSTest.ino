#include "Arduino.h"
#include "SoftwareSerial.h"
#include "IFS_GPS.h"

using namespace IcarusLib;


IFS_GPS *GPS;



void setup() {

  GPS = new IFS_GPS (2,3);
  
Serial.begin(9600);
GPS->initializeGPS(4800);

delay(100);

}

void loop() {


	GPS->readGPS();

	if(!(GPS->getGPSdata()).equals("")) 

		Serial.println(GPS->getGPSdata());

		//delay (1000);

}