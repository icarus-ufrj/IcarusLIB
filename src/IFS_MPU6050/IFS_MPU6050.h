#ifndef _IFS_MPU6050_H_
#define _IFS_MPU6050_H_

#include "Arduino.h"
#include "MPU6050.h"

namespace IcarusLib{
class IFS_MPU6050 {
	MPU6050 *gyroAccel = NULL;

public:
	IFS_MPU6050();
	virtual ~IFS_MPU6050();


};
}

#endif