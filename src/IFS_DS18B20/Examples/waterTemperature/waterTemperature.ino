#include "OneWire.h"
#include "IFS_DS18B20.h"

using namespace IcarusLib;

IFS_DS18B20 *radTemperature;

void setup(){
	radTemperature = new IFS_DS18B20;
	radTemperature->setPort(10);
}

void loop(){
	radTemperature->readTemperature();
}