#include<Arduino.h>
#include"Temperature.h"
#include"Motor.h"
#include"Usound.h"
#define PIR_PIN 2
#define MOT_FEEDBACKPULSE_PIN 3
#define MOT_ROTDIRECTION_PIN 4
#define MOT_INTOPULSE_PIN 5
#define ECHO_PIN 6
#define TRIG_PIN 7

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(MOT_FEEDBACKPULSE_PIN, INPUT);
  pinMode(MOT_ROTDIRECTION_PIN, OUTPUT);
  pinMode(MOT_INTOPULSE_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
    
  Serial.begin(9600);
  Serial.println("test");  
  mlx.begin();  //実行しないとデフォルト値が出続ける
}
Usound US(ECHO_PIN, TRIG_PIN);
Motor M(MOT_FEEDBACKPULSE_PIN, MOT_ROTDIRECTION_PIN, MOT_INTOPULSE_PIN);
bool y=true;
void loop() {

  //超音波センサ実行プログラム
  /*
  Serial.print("distance: ");
  Serial.print(US.echoCatch());
  Serial.println("cm");
  */
  
  //モータの実行プログラム
  
  
  if(y){
    M.rotate(1,10,10);
    y=false;
  }
  
  /*
    Serial.println(10);
    digitalWrite(MOT_ROTDIRECTION_PIN,1);
    for(int i=0;i<1000;i++){
      digitalWrite(MOT_OUTPULSE_PIN,1);
      delay(1);
      digitalWrite(MOT_OUTPULSE_PIN,0);
      delay(1);
    }
    digitalWrite(MOT_ROTDIRECTION_PIN,0);
    for(int i=0;i<1000;i++){
      digitalWrite(MOT_OUTPULSE_PIN,1);
      delay(1);
      digitalWrite(MOT_OUTPULSE_PIN,0);
      delay(1);
    }
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
  Serial.print(T.getAmbientTemperature()); 
  Serial.println("*C");
  Serial.print("Object = ");
  Serial.print(T.getObjectTemperature());
  Serial.println("*C");
  Serial.println();
  delay(1000);
  */
}
