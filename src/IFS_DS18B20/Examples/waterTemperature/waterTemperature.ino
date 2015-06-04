#include "OneWire.h"
#include "IFS_DS18B20.h"

using namespace IcarusLib;

IFS_DS18B20 *radTemperature;

void setup(){
	Serial.begin(9600);
	radTemperature = new IFS_DS18B20;
	radTemperature->setPort(10);
}

void loop(){
	Serial.println(radTemperature->readTemperature());
}