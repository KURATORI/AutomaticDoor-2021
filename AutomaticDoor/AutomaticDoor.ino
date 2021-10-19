#include<Arduino.h>
#include"Temperature.h"
#include"Motor.h"
#include"Usound.h"
#define PIR_PIN 0
#define MOT_INPULSE_PIN 1
#define MOT_ROTDIRECTION_PIN 2
#define MOT_OUTPUlSE_PIN 3
#define ECHO_PIN 4
#define TRIG_PIN 5

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(MOT_INPULSE_PIN, INPUT);
  pinMode(MOT_ROTDIRECTION_PIN, OUTPUT);
  pinMode(MOT_OUTPUlSE_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  
  
  Serial.begin(9600);
  Serial.println("test");  
  mlx.begin();  //実行しないとデフォルト値が出続ける
}

void loop() {

  //超音波センサ実行プログラム
  /*
  Usound US(ECHO_PIN, TRIG_PIN);
  Serial.print("distance: ");
  Serial.print(US.echoCatch());
  Serial.println("mm");
  *
  
  //モータの実行プログラム
  /*
  Motor M(MOT_INPULSE_PIN, MOT_ROTDIRECTION_PIN, MOT_OUTPULSE_PIN);
  bool rotdir = 1;
  float rps = 1000;
  float meter = 100;
  M.rotateMotor(rotdir, rps, meter);
  */
 
  //PIRセンサの実行プログラム
  /*
  if(digitalRead(PIR_PIN) == HIGH)Serial.println("HIGH");
  else Serial.println("Low");
  */

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
