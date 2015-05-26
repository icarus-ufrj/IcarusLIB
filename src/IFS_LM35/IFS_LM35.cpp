#include "IFS_LM35.h"
namespace IcarusLib{

IFS_LM35::IFS_LM35()
{
}

void IFS_LM35::setPort(const unsigned &value){
	pin = value;
}

double IFS_LM35::readTemperature(){
	return analogRead(pin)*CELSIUS_CONVERT;
}

}