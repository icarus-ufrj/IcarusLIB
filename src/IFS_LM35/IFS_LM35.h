#ifndef _IFS_LM35_H_
#define _IFS_LM35_H_

#include "Arduino.h"
/*
 *  The objective of this class is to coordinate a temperature sensor of the model LM35.
 * With this class is possible to create a really simple interface for LM35 and can be scalable to
 * append more sensor with a correct data structure (Without consume to much memory). 
 */
namespace IcarusLib{
class IFS_LM35 {
	// Port associated to the sensor
	unsigned pin;
	//Value to convert the input from sensor to a temperature in Celsius degree [(5/1023)*100]
	const float CELSIUS_CONVERT = 0.4888;
	
public:
	// Function to set the pin associated to the sensor
	void setPort(const unsigned value);
	
	// Function to read the temperature in Celsius degree
	double readTemperature();
};
}

#endif