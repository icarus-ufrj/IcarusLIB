#ifndef _IFS_US1881_H_
#define _IFS_US1881_H_

#include "Arduino.h"

namespace IcarusLib{
class IFS_US1881 {
	unsigned RPM = 0;
	unsigned pin, magnets;
	unsigned long startTime, endTime;
	volatile byte counterMagnet;

public:
	IFS_US1881(unsigned magnets = 1);

	// Function to set the pin associated to the sensor
	void setPort(const unsigned &value);

	// Function to gets a signal change in a specific port
	void getChangeState();

	// Function to get the value of the RPM
	unsigned getRPM();

private:
	// Function to calculate the value of the RPM
	void calculateRPM();
};
}

#endif