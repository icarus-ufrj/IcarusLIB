#ifndef _IFS_MLX90614_H_
#define _IFS_MLX90614_H_
#include "Arduino.h" // verificar o que é WProgram.h, tinha um else com ARDUINO>100
#include "Wire.h"



#define IFS_MLX90614_I2CADDR 0x5A

// RAM
#define IFS_MLX90614_RAWIR1 0x04
#define IFS_MLX90614_RAWIR2 0x05
#define IFS_MLX90614_TA 0x06
#define IFS_MLX90614_TOBJ1 0x07
#define IFS_MLX90614_TOBJ2 0x08
// EEPROM
#define IFS_MLX90614_TOMAX 0x20
#define IFS_MLX90614_TOMIN 0x21
#define IFS_MLX90614_PWMCTRL 0x22
#define IFS_MLX90614_TARANGE 0x23
#define IFS_MLX90614_EMISS 0x24
#define IFS_MLX90614_CONFIG 0x25
#define IFS_MLX90614_ADDR 0x0E
#define IFS_MLX90614_ID1 0x3C
#define IFS_MLX90614_ID2 0x3D
#define IFS_MLX90614_ID3 0x3E
#define IFS_MLX90614_ID4 0x3F



namespace IcarusLib{
class IFS_MLX90614 {

	uint8_t _addr;

	

	public:
		IFS_MLX90614 (uint8_t addr= IFS_MLX90614_I2CADDR);
		boolean begin();
		uint32_t readID(void);

  		double readObjectTempC(void);
 		double readAmbientTempC(void);
  		double readObjectTempF(void);
  		double readAmbientTempF(void);


	private:
		float readTemp(uint8_t reg);

  
  		uint16_t read16(uint8_t addr);
  		void write16(uint8_t addr, uint16_t data);


};
}

#endif







