#include "IFS_DS18B20.h"

namespace IcarusLib{
IFS_DS18B20::IFS_DS18B20()
{
	data = new byte [12];
	addr = new byte [8];
}

IFS_DS18B20::~IFS_DS18B20(){
	delete[] data;
	delete[] addr;
	delete onewire;
}

void IFS_DS18B20::setPort(unsigned value){
	pin = value;
	onewire = new OneWire(pin);
}
	
float IFS_DS18B20::readTemperature(){
	getDataOfSensor();
	return (float)rawData / 16.0;
}
	
void IFS_DS18B20::searchSensor(){
	if (!onewire->search(addr)){
    	onewire->reset_search();
    	return;
  	}
}

void IFS_DS18B20::setParasitePower(){
	onewire->reset();
  	onewire->select(addr);
  	onewire->write(0x44, 1);
}

void IFS_DS18B20::getDataOfSensor(){
	searchSensor();
	setParasitePower();

  	onewire->select(addr);    
  	onewire->write(0xBE);

  	for (int i = 0; i < 9; i++) 
  		data[i] = onewire->read();

  	rawData = (data[1] << 8) | data[0];
  	cfg = (data[4] & 0x60);

    if (cfg == 0x00) 		rawData = rawData & ~7;
    else if (cfg == 0x20) 	rawData = rawData & ~3;
    else if (cfg == 0x40) 	rawData = rawData & ~1;
}

}