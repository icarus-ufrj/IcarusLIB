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

IFS_US1881::~IFS_US1881(){
	delete sensorSingleton;
}

void IFS_US1881::setPort(const unsigned &value){
	pin = value;
}

void IFS_US1881::getChangeState(){
	sensorSingleton->calculateRPM();

}

unsigned IFS_US1881::getRPM(){
	return sensorSingleton->RPM;
}

void IFS_US1881::calculateRPM(){
	// Increment the number of noticed magnets
	counterMagnet++;

	// Check if the wheel gave a full rotation
	if (counterMagnet == magnets+1){

		// Restart the counter
		counterMagnet = 0;

		// Calculating the Time to give a full rotation
		endTime = micros();

		// Calculate the RPM of the Wheel
		RPM = (endTime-startTime);

		// Restarting the Clock
		startTime = micros();
	}
}

}
