#ifndef _IFS_MPU6050_H_
#define _IFS_MPU6050_H_

// Arduino Headers
#include "Arduino.h"
#include "I2Cdev.h"
#include "MPU6050.h"

// C++ Headers
#include <vector>

namespace IcarusLib{
/**
 * @brief [brief description]
 * @details [long description]
 */
class IFS_MPU6050 {
	/**
	 * @brief [brief description]
	 */
	MPU6050 *gyroAccel;
	//@{
	/**
	 * @brief [brief description]
	 */
	unsigned RX,TX;
	//@}

public:
	IFS_MPU6050();
	virtual ~IFS_MPU6050();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param pinRX [description]
	 * @param pinTx [description]
	 */
	void setupPort(unsigned pinRX = 0, unsigned pinTx = 1);
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	std::vector<double> readGyro();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	std::vector<double> readAccel();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	std::vector<double> readGyro();

private:
	/**
	 * @brief [brief description]
	 * @details [long description]
	 */
	void setupMPU6050();
};
}

#endif