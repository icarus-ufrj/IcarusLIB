#include "IFS_SD.h"
#include "SD.h"

namespace IcarusLib{

	//	constructor
	IFS_SD::IFS_SD()
	{
		//sd = new SD;

	}
	
	IFS_SD::~IFS_SD()
	{
		//destroyes the pointer
		//delete sd;

	}

	unsigned IFS_SD::InitializeSD(unsigned cspin)
	{
		if(!SD.begin(cspin))
		{
			//indicates that card failed
			return 0; 
		}	
			//everything ok
			sdtype=cspin;
			return 1;
	}

		//ver se precisa retornar algo e a questão de vector para files
	  unsigned IFS_SD::OpenfileSD (File &namefile, String path,  unsigned preference) 
	  {
	  		//it opens the file on SD card. Preference=0 is for FILE_READ and Preferencie==1 is forFILE_WRITE
	  		if (preference==0)
	  		{	
	  			nameFile= SD.open(path, FILE_READ);
	  			if(nameFile){
	  				return 1; //if everything is ok, returns 1
	  			}
	  		}
	  		if(preference==1)
	  		{	
	  			nameFile= SD.open(path, FILE_WRITE);
	  			if(nameFile){
	  				return 1; //if everything is ok, returns 1
	  			}
	  		}
	  			
	  			return 0; //if there's something wrong

	  }

	  void IFS_SD::ClosefileSD(File &namefile)
	  {
	  		namefile.close();
	  }

	  void IFS_SD::PrintlnfileSD (File &namefile, String data, String BASE)
	  {
	  		namefile.println(data, BASE);

	  }	  

	  void IFS_SD::PrintfileSD (File &namefile, String data, String BASE)
	  {
	  		namefile.print(data, BASE);

	  }	  




}