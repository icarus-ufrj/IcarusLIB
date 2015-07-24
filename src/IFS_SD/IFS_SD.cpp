#include "IFS_SD.h"
#include "SD.h"
#include "Arduino.h"

namespace IcarusLib{

IFS_SD::IFS_SD(){
}
	
IFS_SD::~IFS_SD(){

}

unsigned IFS_SD::InitializeSD(const int cspin) {

	if(!SD.begin(cspin)){
		return 0; 
	}	
	
	sdtype=cspin;
	return 1;
}

unsigned IFS_SD::OpenfileSD (File *namefile, char* path,  unsigned preference) {
	if (preference==0) {
		*namefile= SD.open(path, FILE_READ);
	  
	  if(*namefile){
	  	return 1; //if everything is ok, returns 1
	  }
	}
	
	if(preference==1){	
		*namefile= SD.open(path, FILE_WRITE);
	  if(*namefile){
	  	return 1; //if everything is ok, returns 1
	  }
	}
	  			
	return 0; //if there's something wrong
}

	  
void IFS_SD::ClosefileSD(File *namefile){
	namefile->close();
}


	  
void IFS_SD::PrintlnfileSD (File *namefile, String &data){
	namefile->println(data);
}	  
	  
void IFS_SD::PrintfileSD (File *namefile, String data){
	namefile->print(data);

}	  
}