#include <IFS_LM35.h>

using namespace IcarusLib; 

const unsigned SENSORPORT = A0;
const unsigned baudRate = 9600;
IFS_LM35 *extRadTemp;

void setup(){
	extRadTemp = new IFS_LM35;
	extRadTemp->setPort(SENSORPORT);
	Serial.begin(baudRate);
}

void loop(){
	Serial.println(extRadTemp->readTemperature());
}