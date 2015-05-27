#ifndef _IFS_DS18B20_H_
#define _IFS_DS18B20_H_

#include <OneWire.h>

namespace IcarusLib{
class IFS_DS18B20 {
	OneWire *radTemperature = NULL;

public:
	IFS_DS18B20();
	virtual ~IFS_DS18B20();
};
}

#endif