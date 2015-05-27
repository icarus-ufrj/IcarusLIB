#include "IFS_US1881.h"
namespace IcarusLib{

IFS_US1881::IFS_US1881(unsigned magnets) :
	magnets(magnets)
{
	startTime = micros();
	attachInterrupt(0, getChangeState, CHANGE);
}

void IFS_US1881::setPort(const unsigned &value){
	pin = value;
}

void IFS_US1881::getChangeState(){
 	counterMagnet++;
}

unsigned IFS_US1881::getRPM(){
	return RPM;
}

void IFS_US1881::calculateRPM(){

}

}