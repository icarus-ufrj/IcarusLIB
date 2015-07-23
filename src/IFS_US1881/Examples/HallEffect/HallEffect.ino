#include <IFS_US1881.h>

using namespace IcarusLib;

unsigned baudRate = 9600;
unsigned digitalPort = 2;
IFS_US1881* sensorHall = new IFS_US1881(1);

void setup(){
	Serial.begin(baudRate);
	sensorHall->setPort(digitalPort);
}

void loop(){
	Serial.print("RPM = ");
	Serial.println(sensorHall->getRPM());
}