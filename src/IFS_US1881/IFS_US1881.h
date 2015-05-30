#ifndef _IFS_US1881_H_
#define _IFS_US1881_H_

#include "Arduino.h"

namespace IcarusLib{
class IFS_US1881 {
	
	static IFS_US1881 *sensorSingleton;

	unsigned RPM = 0;
	unsigned pin, magnets;
	unsigned long startTime, endTime, intervalTime;
	volatile unsigned counterMagnet = 0;

public:
	IFS_US1881(unsigned magnets = 1);

	// Function to set the pin associated to the sensor
	void setPort(const unsigned &value);

	// Function to get the value of the RPM
	unsigned getRPM();

	// Function to set the number of magnets passed through the sensor
	void incrementCounterMagnet();

	// Function to get the number of magnets passed through the sensor
	unsigned getCounterMagnet();

private:
	// Function to gets a signal change in a specific port
	static void getChangeState();
	
	// Function to calculate the value of the RPM
	void calculateRPM();
};
}

#endif