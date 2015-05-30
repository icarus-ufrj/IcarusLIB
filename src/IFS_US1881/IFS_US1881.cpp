#include "IFS_US1881.h"
namespace IcarusLib{

IFS_US1881 *IFS_US1881::sensorSingleton;

IFS_US1881::IFS_US1881(unsigned magnets) :
	magnets(magnets)
{
	startTime = micros();
	sensorSingleton = this;
	attachInterrupt(0, &IFS_US1881::getChangeState, RISING);
}

void IFS_US1881::setPort(const unsigned &value){
	pin = value;
}

void IFS_US1881::incrementCounterMagnet(){
	counterMagnet++;
	if (counterMagnet == magnets + 1){
		// Restart the counter
		counterMagnet = 0;
		
		// Calculating the Time to give a full rotation
		endTime = micros();
		intervalTime = endTime - startTime;

		// Restarting the Clock
		startTime = micros();
	}
}

unsigned IFS_US1881::getCounterMagnet(){
	return counterMagnet;
}

void IFS_US1881::getChangeState(){
	sensorSingleton->incrementCounterMagnet();

	//
	if(sensorSingleton->getCounterMagnet() == 0){
		sensorSingleton->calculateRPM();
	}
}

unsigned IFS_US1881::getRPM(){
	return RPM;
}

void IFS_US1881::calculateRPM(){
	
}

}