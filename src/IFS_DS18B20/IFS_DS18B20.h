#ifndef _IFS_DS18B20_H_
#define _IFS_DS18B20_H_

#include "Arduino.h"
#include "OneWire.h"
/*
 *  The objective of this class is to coordinate a waterproof temperature sensor of the model DS18B20.
 * With this class is possible to create a really simple interface for DS18B20 and can be scalable to
 * append more sensors with a correct data structure (Without consume to much memory).
 * The class is also prepared to avoid memory leak. 
 */
namespace IcarusLib{
class IFS_DS18B20 {
	// Instance of class OneWire to control the sensor's methods
	OneWire *onewire;
	
	// Value associated with the Pin which receives data from the sensor
	unsigned pin;
	
	// Raw data associated with the temperature in DS18B20
	int16_t rawData;
	
	// Array of bytes to request data and address of the sensor
	byte *data;
	byte *addr;
	//
	// Config parameter associated with the sensor. Will check how to get raw data from the sensor.
	byte cfg;

public:
	IFS_DS18B20();
	virtual ~IFS_DS18B20();
	
	// Function to set the pin associated to the sensor. Need to be a digital port.
	void setPort(const unsigned &value);
	
	// Function to read the temperature in Celsius degree.
	float readTemperature();

private:
	// Function to check if sensor is available.
	void searchSensor();

	// Function to start the conversion of the sensor with parasite power ON.
	void setParasitePower();

	// Function to extract a raw value of the sensor with the temperature associated.
	void getDataOfSensor();
};
}

#endif