#include <IFS_LM35.h>

using namespace IcarusLib; 

const unsigned SENSORPORT = A0;
const unsigned baudRate = 9600;
IFS_LM35 *extRadTemp;

void setup(){
	Serial.begin(baudRate);
	extRadTemp = new IFS_LM35;
	extRadTemp->setPort(SENSORPORT);
}

void loop(){
	Serial.println(extRadTemp->readTemperature());
}