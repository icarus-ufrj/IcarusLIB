#ifndef _IFS_US1881_H_
#define _IFS_US1881_H_

#include "Arduino.h"

namespace IcarusLib{
class IFS_US1881 {
	unsigned pin;
	unsigned RPM;
	volatile unsigned counterMagnet;

public:
	IFS_US1881();
	virtual ~IFS_US1881();

	// Function to set the pin associated to the sensor
	void setPort(const unsigned &value);

	// Function to gets a signal change in a specific port
	void getChangeState();

	// Function to read the RPM from a magnet
	unsigned readRPM();
};
}

#endif