#ifndef _IFS_DS18B20_H_
#define _IFS_DS18B20_H_

#include "Arduino.h"
#include "OneWire.h"
/*
 *
 */
namespace IcarusLib{
class IFS_DS18B20 {
	//
	OneWire *onewire;
	//
	unsigned pin;
	//
	int16_t rawData;
	//
	byte *data;
	byte *addr;
	//
	byte cfg;

public:
	IFS_DS18B20();
	virtual ~IFS_DS18B20();
	//
	void setPort(unsigned value);
	//
	float readTemperature();

private:
	//
	void searchSensor();

	// This function start the conversion of the sensor with parasite power ON
	void setParasitePower();

	//
	void getDataOfSensor();
};
}

#endif