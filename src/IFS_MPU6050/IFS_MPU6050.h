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
	unsigned SDA,SCL;
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

	 //it considerates UNO board
	bool Initialize(unsigned pinSDA = A4, unsigned pinSCL = A5);
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
	

private:
	/**
	 * @brief [brief description]
	 * @details [long description]
	 */
	bool setupMPU6050();
};
}

#endif