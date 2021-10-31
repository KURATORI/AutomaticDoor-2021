#include<Arduino.h>
#include"Temperature.h"
#include"Motor.h"
#include"Usound.h"
#define PIR_PIN 2
#define MOT_FEEDBACKPULSE_PIN 3
#define MOT_ROTDIRECTION_PIN 4
#define MOT_INTOPULSE_PIN 5
#define DIS_ECHO_PIN 6
#define DIS_TRIG_PIN 7
#define PP1_ECHO_PIN 8
#define PP1_TRIG_PIN 9
#define PP2_ECHO_PIN 10
#define PP2_TRIG_PIN 11
#define LED1_PIN 12
#define LED2_PIN 13

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() {
  
  pinMode(PIR_PIN, INPUT);
  pinMode(MOT_FEEDBACKPULSE_PIN, INPUT);
  pinMode(MOT_ROTDIRECTION_PIN, OUTPUT);
  pinMode(MOT_INTOPULSE_PIN, OUTPUT);
  pinMode(DIS_ECHO_PIN, INPUT);
  pinMode(DIS_TRIG_PIN, OUTPUT);
  pinMode(PP1_ECHO_PIN, OUTPUT);
  pinMode(PP1_TRIG_PIN, OUTPUT);
  pinMode(PP2_ECHO_PIN, OUTPUT);
  pinMode(PP2_TRIG_PIN, OUTPUT);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
    
  Serial.begin(9600);
  Serial.println("test");  
  mlx.begin();  //実行しないとデフォルト値が出続ける
}
Usound DIS_US(DIS_ECHO_PIN, DIS_TRIG_PIN);
Usound PP1_US(PP1_ECHO_PIN, PP1_TRIG_PIN);
Usound PP2_US(PP2_ECHO_PIN, PP2_TRIG_PIN);
Motor M(MOT_FEEDBACKPULSE_PIN, MOT_ROTDIRECTION_PIN, MOT_INTOPULSE_PIN);
Temperature T;
//bool y=true;
void loop() {
  
  //超音波センサ実行プログラム
  /*
  Serial.print("distance: ");
  Serial.print(US.echoCatch());
  Serial.println("cm");
  */
  
  //モータの実行プログラム
  /*
  Motor M(MOT_FEEDBACKPULSE_PIN, MOT_ROTDIRECTION_PIN, MOT_INTOPULSE_PIN);
  if(y){
    M.rotate(1,10,10);
    y=false;
  }
  */
  
 
  //PIRセンサの実行プログラム
  /*
  if(digitalRead(PIR_PIN) == HIGH)Serial.println("HIGH");
  else Serial.println("Low");
  */

  //温度センサの実行プログラム
  /*
  Serial.print("Ambient = ");
  Serial.print(T.getAmbientTemperature()); 
  Serial.println("*C");
  Serial.print("Object = ");
  Serial.print(T.getObjectTemperature());
  Serial.println("*C");
  Serial.println();
  delay(1000);
  */

  
  
  /*
  //廊下→教室のプログラム
  digitalWrite(TRIG_PIN,HIGH);
  for(){
    if(10 <= US.echoCatch()){
      digitalWrite(BLUE_PIN,HIGH);
      delay(3000);
      if(T.getObjectTemperature() < 37.5){
        digitalWrite(GREEN_PIN,HIGH);
        //モーター割り込み
        digitalWrite(BLUE_PIN,LOW);
        digitalWrite(GREEN_PIN,LOW);
        }
        
      else{
        digitalWrite(BLUE_PIN,LOW);
        digitalWrite(RED_PIN,HIGH);
        delay(2000);
        digitalWrite(RED_PIN,LOW);
      }
      
    }
  }

  //教室→廊下のプログラム
   if(digitalRead(PIR_PIN) == HIGH)Serial.println("HIGH");
  else Serial.println("Low");
  */
}
