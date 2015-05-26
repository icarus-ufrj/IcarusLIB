#ifndef _IFS_LM35_H_
#define _IFS_LM35_H_

#include "Arduino.h"

namespace IcarusLib{
class IFS_LM35 {
	// Port associated to the sensor
	unsigned pin;
	//Value to convert the input from sensor to a temperature in Celsius degree
	const float CELSIUS_CONVERT = 0.48875855;
	
public:
	IFS_LM35();
	
	// Function to set the pin associated to the sensor
	void setPort(const unsigned &value);
	
	// Function to read the temperature in Celsius degree
	double readTemperature();
};
}

#endif