#include<Arduino.h>
#include"Temperature.h"
#define PIR_PIN 7

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() {
  Serial.begin(9600);
  Serial.println("test");  
  mlx.begin();  //実行しないとデフォルト値が出続ける
}

void loop() {

  if(digitalRead(PIR_PIN) == HIGH)Serial.println("HIGH");
  else Serial.println("Low");

  //温度センサの実行プログラム
  /*
  Temperature T;
  Serial.print("Ambient = ");
  Serial.print(T.getObjectTemperature()); 
  Serial.println("*C");
  Serial.print("Object = ");
  Serial.print(T.getAmbientTemperature());
  Serial.println("*C");
  Serial.println();
  delay(1000);
  */
}
