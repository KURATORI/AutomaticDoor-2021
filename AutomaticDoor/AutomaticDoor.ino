#include<Arduino.h>
#include<LiquidCrystal_I2C.h>
#include"Motor.h"
#include"Usound.h"
#include"src/libraries/Adafruit_MLX90614_Library/Adafruit_MLX90614.h"

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

Adafruit_MLX90614 mlx = Adafruit_MLX90614();
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
  Serial.println("test");  
  mlx.begin();  //実行しないとデフォルト値が出続ける
}

Usound DIS_US(DIS_ECHO_PIN, DIS_TRIG_PIN);
Usound EX_US(EX_ECHO_PIN, EX_TRIG_PIN);
Motor M(MOT_FEEDBACKPULSE_PIN, MOT_ROTDIRECTION_PIN, MOT_INTOPULSE_PIN);

float dis;    //温度を測るときの距離
float temp[4] = {0, 0, 0, 0};  //測定した温度
int tempnum = 0;  //tempの添え字
float tempave;  //温度の平均
float ex_dis = 10.0; //手動開閉のときの距離

void loop() {
  //本番用
  //LED
  digitalWrite(LED1_PIN,LOW);
  digitalWrite(LED2_PIN,HIGH);
  
  
  //手動で内側から開閉する
  ex_dis = EX_US.echoCatch();
  Serial.print(ex_dis);
  if(0.1 < ex_dis && ex_dis < 3.0){
      //LCD OPEN
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("OPEN");
      
      M.rotate(0,20,60,1); //開く
      delay(1000);

      //LCD CLOSE
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("CLOSE");
      
      M.rotate(1,10,60,1);//閉まる
      delay(1000);
  }
  dis = DIS_US.echoCatch();
  Serial.print("人との距離:");
  Serial.print(DIS_US.echoCatch());
  //Serial.print(" 温度:");
  //Serial.println(mlx.readObjectTempC());
  if(dis > 10 && dis < 15){
    Serial.println("echo_OK");
    if(tempnum < 4){
      temp[tempnum] = (mlx.readObjectTempC() - (((3.3-3.0)*0.6)) + 2.5);
      //Serial.print(tempnum);
      //Serial.print(" 測定温度:");
      //Serial.println(temp[tempnum]);
      tempnum++;
      //delay(100);
    }
    else {
      tempave = (temp[1] + temp[2] + temp[3]) / 3;
      Serial.print("平均温度");
      Serial.println(tempave);
      if(30 < tempave && tempave < 37.5){
        //LCD OPEN
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("\xc0\xb2\xb5\xdd");
        lcd.print(tempave);
        lcd.print("\xDF");
        lcd.print("C");
        lcd.setCursor(0, 1);
        lcd.print("OPEN");
        Serial.print("tmp_OK");
        //LED
        digitalWrite(LED1_PIN,HIGH);
        digitalWrite(LED2_PIN,LOW);
        
        M.rotate(0,25,60,1); //開く

        //LCD CLOSE
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("\xc0\xb2\xb5\xdd");
        lcd.print(tempave);
        lcd.print("\xDF");
        lcd.print("C");
        lcd.setCursor(0, 1);
        lcd.print("CLOSE");
        //LED
        digitalWrite(LED1_PIN,LOW);
        digitalWrite(LED2_PIN,HIGH);
        delay(5000);
        //LED
        digitalWrite(LED1_PIN,HIGH);
        digitalWrite(LED2_PIN,LOW);
        
        M.rotate(1,15,60,1);  //閉まる
        delay(1000);
      }
      else{
        Serial.print("tmp_NG");
      }
      for(int i=0;i<3;i++)temp[i]=0;
      tempnum = 0;
    }
  }
  //後ろ
  else if(dis <= 10){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("\xb3\xbc\xdb\xc6\xd3\xc4\xde\xda");
  }
  //前
  else if(dis >= 15){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("\xcf\xb4\xcd\xbd\xbd\xd2");
  }
  Serial.println(" ");
  
 
  //ドア往復するだけ
  /*
  M.rotate(0,20,60,0); //開く
  delay(1000);
  M.rotate(1,10,60,0);//閉まる
  delay(1000);
  */
  
  //Serial.print(b);
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
  Serial.print(mlx.getAmbientTemperature()); 
  Serial.println("*C");
  Serial.print("Object = ");
  Serial.print(mlx.getObjectTemperature());
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
