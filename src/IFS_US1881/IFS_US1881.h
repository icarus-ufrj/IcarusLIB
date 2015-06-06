#ifndef _IFS_US1881_H_
#define _IFS_US1881_H_

#include "Arduino.h"
/*
 *  This Class is a simple implementation for a Sensor Hall (US1881) to measure RPM of a Wheel.
 * It's a high level approach to get a AttachInterrupt when a magnet pass through the sensor and
 * it's easy to append more sensor with a correct data structure (Without consume to much memory). 
 *
 * This Class need to be improved. The correct way of use it should be by launch a new thread.
 * But this is not possible (yet) in an Arduino board. To not give error or unexpected behavior you
 * need guarantee the RPM to be measured is really much slower than the arduino Clock speed.
 */
namespace IcarusLib{
class IFS_US1881 {
	// Static member to acess the class through the this pointer and
	// invoke methods inside the static method getChangeState
	static IFS_US1881 *sensorSingleton;
	
	// Value of the current RPM from the Wheel. Initialize with 0
	float RPM=0;

	// Numerical value of the digital pin associated with the AttachInterrupt port
	// and the number of magnets in the specified wheel.
	// Tip:
	// Arduino Mega only accept 6 AttachInterrupt ports (2,3,18,19,20,21)
	// More details can be found at : http://www.arduino.cc/en/Reference/AttachInterrupt
	unsigned pin, magnets;
	
	// Variable to catch the Interval of time to the wheel give a full rotation.
	unsigned long startTime, endTime;
	
	// Variable to count how many magnets passed through the sensor
	unsigned counterMagnet = 0;

public:
	IFS_US1881(unsigned magnets = 1);
	virtual ~IFS_US1881();

	// Function to set the pin associated to the sensor
	void setPort(const unsigned &value);

	// Function to get the value of the RPM
	unsigned getRPM();

	// Function to calculate the value of the RPM
	void calculateRPM();

private:
	// Function to gets a signal change in a specific port
	static void getChangeState();
};
}

#endif