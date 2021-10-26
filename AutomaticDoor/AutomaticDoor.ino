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
//#define  
#define BLUE_PIN 9 
#define GREEN_PIN 10
#define RED_PIN 11
//#define
//#define

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
bool y=true;

float cmperstep = (float)8/3200;
float check = (float)1/cmperstep;

void loop() {

  //超音波センサ実行プログラム
  
  Serial.print("distance: ");
  Serial.print(US.echoCatch());
  Serial.println("cm");
  
  
  //モータの実行プログラム
  /*
  Motor M(MOT_FEEDBACKPULSE_PIN, MOT_ROTDIRECTION_PIN, MOT_INTOPULSE_PIN);
  if(y){
  M.rotate(1,10,100);
  y=false;
  }
  
  
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
  
  if(digitalRead(PIR_PIN) == HIGH)Serial.println("HIGH");
  else Serial.println("Low");
  

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
