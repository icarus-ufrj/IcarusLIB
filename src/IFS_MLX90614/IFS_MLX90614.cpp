#include "IFS_MLX90614.h"
#include "Wire.h"


namespace IcarusLib{
	
IFS_MLX90614::IFS_MLX90614 (uint8_t addri2c){
	_addr = addri2c;
}


bool IFS_MLX90614::begin(void){
	Wire.begin();
	return true;
}

double IFS_MLX90614::readObjectTempF (void){
	return (readTemp(IFS_MLX90614_TOBJ1)*9/5)+32;
}

double IFS_MLX90614::readAmbientTempF(void) {
	return (readTemp(IFS_MLX90614_TA) * 9 / 5) + 32;
}

double IFS_MLX90614::readObjectTempC(void) {
	return readTemp(IFS_MLX90614_TOBJ1);
}

double IFS_MLX90614::readAmbientTempC(void) {
	return readTemp(IFS_MLX90614_TA);
}

float IFS_MLX90614::readTemp(uint8_t reg) {
	float temperature;
  
	temperature = read16(reg);
	temperature *= .02;
	temperature  -= 273.15;
	return temperature;
}

uint16_t IFS_MLX90614::read16(uint8_t a) {
	uint16_t ret;

 	Wire.beginTransmission(_addr); // start transmission to device 
  	Wire.write(a); // sends register address to read from
  	Wire.endTransmission(false); // end transmission
  
   	Wire.requestFrom(_addr, (uint8_t)3);// send data n-bytes read
  	ret = Wire.read(); // receive DATA
  	ret |= Wire.read() << 8; // receive DATA

  	uint8_t pec = Wire.read();

  	return ret;
}
}