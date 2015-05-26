#ifndef _IFS_LM35_H_
#define _IFS_LM35_H_

#include "Arduino.h"

namespace IcarusLib{
class IFS_LM35 {
	const float CELSIUS_CONVERT = 0.48875855;
	unsigned pin;

public:
	/**
	 *
	 */
	IFS_LM35();
	/**
	 *
	 */
	void setPort(const unsigned &value);
	/**
	 *
	 */
	double readTemperature();
};
}

#endif