#include<Arduino.h>
//#include"Tempreture.h"
#include"src/libraries/Adafruit_MLX90614_Library/Adafruit_MLX90614.h"

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("test");  
  mlx.begin();  //実行しないとデフォルト値が出続ける
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC()); 
  Serial.print("*C\tObject = "); Serial.print(mlx.readObjectTempC());
  delay(1000);
}
