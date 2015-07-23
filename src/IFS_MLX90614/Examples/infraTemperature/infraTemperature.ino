#include <Wire.h>
#include <IFS_MLX90614.h>

using namespace IcarusLib;

IFS_MLX90614 mlx = IFS_MLX90614();

void setup() {
  Serial.begin(9600);

  Serial.println("IFS_MLX90614 test");  

  mlx.begin();  
}

void loop() {
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC()); 
  Serial.print("*C\tObject = "); Serial.print(mlx.readObjectTempC()); Serial.println("*C");
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempF()); 
  Serial.print("*F\tObject = "); Serial.print(mlx.readObjectTempF()); Serial.println("*F");

  Serial.println();
  delay(500);
}