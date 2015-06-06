#include <IFS_SD.h>
#include "Arduino.h"
#include <SD.h>
#include <SPI.h>

using namespace IcarusLib;

const int chipSelect =10;
int finalValue;
int sensorValue = 0;
IFS_SD *sdcard;



void setup()  
  {
    // Open serial communications and wait for port to open:
    Serial.begin(9600);
    Serial.println("Iniciando o cartão SD");
  
    if(sdcard->InitializeSD (chipSelect))
      return;

      Serial.println("Cartao inicializado");
}

void loop() // run over and over
{
  String dataString=";";
  File dataFile;
  
  
  if(sd->OpenfileSD(dataFile, dataString, FILE_WRITE ))
  {
    
    sd->PrintlnfileSD(dataFile, dataString, "HEX");
    sd->ClosefileSD();
    
  } 
  
  else
  {
    return;
  } 
    
    
    
    delay(1000);
  
}
