#include <IFS_SD.h>
#include "Arduino.h"
#include <SD.h>


using namespace IcarusLib;

const int chipSelect =10;
int finalValue;
int sensorValue = 0;
IFS_SD *sd;



void setup()  
  {
    sd = new IFS_SD;
    // Open serial communications and wait for port to open:
    Serial.begin(9600);
    Serial.println("Iniciando o cartão SD");
  
    if(sd->InitializeSD (chipSelect))
      return;

      Serial.println("Cartao inicializado");
}

void loop() // run over and over
{
  String dataString=";";
  File dataFile;
  
  
  if(sd->OpenfileSD(dataFile, "datalog.csv", 0 ))
  {
    
    sd->PrintlnfileSD(dataFile, dataString, "HEX");
    sd->ClosefileSD(dataFile);
    
  } 
  
  else
  {
    Serial.println ("Erro no cartao");
  } 
    
    
    
    delay(1000);
  
}