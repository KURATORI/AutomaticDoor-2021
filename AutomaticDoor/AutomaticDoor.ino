#include<Arduino.h>
#include<LiquidCrystal_I2C.h>
#include"Motor.h"
#include"Usound.h"

#define MOT_FEEDBACKPULSE_PIN 2
#define MOT_ROTDIRECTION_PIN 3
#define MOT_INTOPULSE_PIN 4
#define DIS_ECHO_PIN 5
#define DIS_TRIG_PIN 6
#define PP1_ECHO_PIN 7
#define PP1_TRIG_PIN 8
#define PP2_ECHO_PIN 9
#define PP2_TRIG_PIN 10
#define EX_ECHO_PIN 11
#define EX_TRIG_PIN 12
#define LED1_PIN 13 //緑色LED
#define LED2_PIN 14 //赤色LED

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  
  pinMode(MOT_FEEDBACKPULSE_PIN, INPUT);
  pinMode(MOT_ROTDIRECTION_PIN, OUTPUT);
  pinMode(MOT_INTOPULSE_PIN, OUTPUT);
  pinMode(DIS_ECHO_PIN, INPUT);
  pinMode(DIS_TRIG_PIN, OUTPUT);
  pinMode(PP1_ECHO_PIN, INPUT);
  pinMode(PP1_TRIG_PIN, OUTPUT);
  pinMode(PP2_ECHO_PIN, INPUT);
  pinMode(PP2_TRIG_PIN, OUTPUT);
  pinMode(PP2_ECHO_PIN, INPUT);
  pinMode(PP2_TRIG_PIN, OUTPUT);
  pinMode(EX_ECHO_PIN, INPUT);
  pinMode(EX_TRIG_PIN, OUTPUT);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  lcd.init();                      
  lcd.backlight();
  Serial.begin(9600);
}

Usound DIS_US(DIS_ECHO_PIN, DIS_TRIG_PIN);
Usound EX_US(EX_ECHO_PIN, EX_TRIG_PIN);
Motor M(MOT_FEEDBACKPULSE_PIN, MOT_ROTDIRECTION_PIN, MOT_INTOPULSE_PIN);

float dis;    //温度を測るときの距離
float ex_dis = 10.0; //手動開閉のときの距離

void loop() {
  //LED
  digitalWrite(LED1_PIN,LOW);
  digitalWrite(LED2_PIN,HIGH);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("\xc3\xa6\xb6\xbb\xde\xbc\xc3\xc8");
  
  //手動で内側から開閉する
  ex_dis = EX_US.echoCatch();
  if(0.1 < ex_dis && ex_dis < 3.0){
      //LCD OPEN
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("OPEN");
      M.rotate(0,25,81,1); //開く
      delay(5000);
      //LCD CLOSE
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("CLOSE");
      M.rotate(1,25,82,1);//閉まる
      delay(1000);
  }
  dis = DIS_US.echoCatch();
  if(dis > 0.1 && dis < 10){
    //LCD OPEN
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("OPEN");
    //LED
    digitalWrite(LED1_PIN,HIGH);
    digitalWrite(LED2_PIN,LOW);
    M.rotate(0,25,81,1); //開く
    //LCD CLOSE
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("CLOSE");
    //LED
    digitalWrite(LED1_PIN,LOW);
    digitalWrite(LED2_PIN,HIGH);
    delay(5000);
    //LED
    digitalWrite(LED1_PIN,HIGH);
    digitalWrite(LED2_PIN,LOW);
    M.rotate(1,25,82,1);  //閉まる
    delay(1000);
  }
}
