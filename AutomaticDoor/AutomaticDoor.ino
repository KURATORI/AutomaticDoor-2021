#include<Arduino.h>
#include"Tempreture.h"

Tempreture thermometer;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("test");  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(thermometer.getObjectTempreture());
  Serial.println(thermometer.getAmbientTempreture());
  delay(1000);
}
