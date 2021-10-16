#include<Arduino.h>
#include"Temperature.h"

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() {
  Serial.begin(9600);
  Serial.println("test");  
  mlx.begin();  //実行しないとデフォルト値が出続ける
}

void loop() {
  
  Temperature T;
  Serial.print("Ambient = ");
  Serial.print(T.getObjectTemperature()); 
  Serial.println("*C");
  Serial.print("Object = ");
  Serial.print(T.getAmbientTemperature());
  Serial.println("*C");
  Serial.println();
  delay(1000);
  
}
