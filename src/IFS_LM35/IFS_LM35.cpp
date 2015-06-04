#include "IFS_LM35.h"
namespace IcarusLib{

void IFS_LM35::setPort(const unsigned &value){
	pin = value;
}

double IFS_LM35::readTemperature(){
	return analogRead(pin)*CELSIUS_CONVERT;
}

}