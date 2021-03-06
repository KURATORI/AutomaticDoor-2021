
#include"Motor.h"
  #ifndef INCLUDE_SOFTWARERESET
  #define INCLUDE_SOFTWARERESET
  #include"src/libraries/SoftwareReset/SoftwareReset.h"
  #endif

Motor::Motor(int pin1, int pin2, int pin3)
: PP1_US(7,8),PP2_US(9,10){
  feedbackpulse_pin = pin1;    
  intopulse_pin_open = pin2; 
  intopulse_pin_close = pin3; 
}

void Motor::setRotateDirection(bool rotdirection){
  this->rotdirection = rotdirection;
  return;
}

void Motor::setSpeed(int centimeter_per_sec){
  this->centimeter_per_sec = centimeter_per_sec;
  return;
}

void Motor::rotate(){
  return;
}

void Motor::rotate(bool rotdirection, float centimeter_per_sec, float movingdistance, bool sensorcheck){

  float rounddown = 8*(7.2/360);//movingdistanceを、この値の倍数に近いほうで丸める
  //ex. rounddown = 0.16, movingdistance = 0.31のとき、rounddownの倍数に達していないため0.32に丸める
  
  float gap = float((100*(int)movingdistance) % (100*(int)rounddown));//丸め誤差の大きさ
  Serial.print("gap:");
  Serial.print(gap);
  if(gap == 0){
    //丸め誤差がなければ移動距離に修正を加えない
    this->movingdistance = movingdistance;
    Serial.println("movingdistance doesn't change");
  }
  else{
    if(gap < rounddown/2.0){
      this->movingdistance = movingdistance - gap/100;
      Serial.println("movingdistance decreased");
    }
    else{
      this->movingdistance = movingdistance + (rounddown - gap/100);
      Serial.println("movingdistance increased");
    }
  }
  Serial.println(this->movingdistance);
  /*
  if(float((100*(int)movingdistance) % (100*(int)rounddown))/100.0 < rounddown/2.0){
    this->movingdistance = movingdistance - float((100*(int)movingdistance) % (100*(int)rounddown))/100.0;
  }
  else{
    this->movingdistance = movingdistance + (rounddown - (float((100*(int)movingdistance) % (100*(int)rounddown))/100.0));
  }*/
  
  this->rotdirection = rotdirection;
  this->centimeter_per_sec = centimeter_per_sec;
  this->sensorcheck = sensorcheck;

  //digitalWrite(rotdirection_pin,this->rotdirection);

  float cmperstep = (float)8/3200; //(1周あたり)8cm:3200ステップ[cm/step]
  float steppercm = (float)1/cmperstep;  //1cm毎ステップ  [step/cm]

  //delaytimeはパルスを送り出す周期。速度と関連する
  double delaytime = cmperstep/centimeter_per_sec/2*1000*1000;//[μs]
  //double delaytime = (float)0.02/centimeter_per_sec*1000;//[ms]
  double steps = this->movingdistance/cmperstep; //必要ステップ数
  
  //フィードバックを測定するための変数
  long feedback_sum = 0;  //カウントしたフィードバック数
  long feedback_expected = steps/(rounddown*steppercm); //総ステップ数から予想される総フィードバック数

  //0除算を避ける
  for(long i=1;i<steps+1;i++){
    
    //パルスを送ってモータを回す
    if(rotdirection == 0){
      digitalWrite(intopulse_pin_open,HIGH);
      delayMicroseconds(delaytime);
      digitalWrite(intopulse_pin_open,LOW);
      delayMicroseconds(delaytime);
    }
    else if(rotdirection == 1){
      digitalWrite(intopulse_pin_close,HIGH);
      delayMicroseconds(delaytime);
      digitalWrite(intopulse_pin_close,LOW);
      delayMicroseconds(delaytime);
    }
    
    //フィードバックパルスを受け取る
    /*フィードバックしょりは不安定なのでコメントアウト
    if(digitalRead(feedbackpulse_pin) == LOW){  //パルスはLOW
      //一定周期で来るはずのパルスが来なければ
      if(i%long(rounddown*steppercm)!=0){
        Serial.print("Door bubmped into something!  step:");
        Serial.println(i);
        delay(100);
        softwareReset::simple();//プログラム再起動
      }
      //Serial.print("feedback incoming, step is :");
      //Serial.println(i);
      feedback_sum++;
    }
    */

    //センサをチェックする
    if(sensorcheck){
      //1cm進むごとにチェック
      if(this->rotdirection == 1){//ドアが閉じる場合にのみ挟まり検知
        if(i%(int)steppercm == 0){
          //Serial.print("check: ");
          //Serial.print(i);
          //Serial.print(" ");
          //Serial.println(PP1_US.echoCatch());
          if((int)PP1_US.echoCatch() < 70 || (int)PP2_US.echoCatch() < 70){
            Serial.println("Someone is between the door");
            delay(1000);
            Motor back(this->feedbackpulse_pin,this->intopulse_pin_open,this->intopulse_pin_close);
            back.rotate(0,this->centimeter_per_sec,(float)(i)*cmperstep,this->sensorcheck);
            i = 1;
            delay(5000);
          }
        }
      }
    }
    
  }

  /*フィードバック処理は不安定なのでコメントアウト
  //フィードバックでずれの修正
  int feedback_differ = abs(feedback_expected - feedback_sum);
  Serial.print("expectation: ");
  Serial.print(feedback_expected);
  Serial.print("  actual sum: ");
  Serial.println(feedback_sum);
  if(feedback_differ != 0){
    Serial.println("feedback is different");
    if(feedback_expected < feedback_sum){
      //超過なら回転方向を反転
      this->rotdirection *= -1;
      //digitalWrite(rotdirection_pin,this->rotdirection);//2パルス方式ではこの一行は意味をなさない
    }
    for(int j = 0; j < feedback_differ*(steppercm*rounddown);j++){

      //パルスを送ってモータを回す
      if(rotdirection == 0){
        digitalWrite(intopulse_pin_open,HIGH);
        delayMicroseconds(delaytime);
        digitalWrite(intopulse_pin_open,LOW);
        delayMicroseconds(delaytime);
      }
      else if(rotdirection == 1){
        digitalWrite(intopulse_pin_close,HIGH);
        delayMicroseconds(delaytime);
        digitalWrite(intopulse_pin_close,LOW);
        delayMicroseconds(delaytime);
      }

      if(sensorcheck){
        //1cm進むごとにチェック
        if(this->rotdirection == 1){
          if(j%(int)steppercm == 0){
            Serial.print("check: ");
            Serial.print(j);
            Serial.print(" ");
            Serial.println(PP1_US.echoCatch());

            while((int)PP1_US.echoCatch() < 70 ||(int)PP2_US.echoCatch() < 70){
              Serial.println("danger");
              delay(3000);
            }
          }
        }
      }
    }
  }
  */
  
  return;
}

/*使っていない間に更新が嵩んで修正できないのでコメントアウト
void Motor::rotate_easing(bool rotdirection, float centimeter_per_sec, float movingdistance, bool sensorcheck, float easein, float easeout){

  this->rotdirection = rotdirection;
  this->centimeter_per_sec = centimeter_per_sec;
  this->movingdistance = movingdistance;  //ドア幅に合わせるなら80cmぐらい？

  digitalWrite(rotdirection_pin,this->rotdirection);

  float cmperstep = (float)8/3200; //(1周あたり)8cm:3200ステップ
  float steppercm = (float)1/cmperstep;  //1cm毎ステップ  [step/cm]
  double delaytime = cmperstep/centimeter_per_sec/2*1000*1000;//[μs]
  //double delaytime = (float)0.02/centimeter_per_sec*1000;//[ms]
  double steps = movingdistance/cmperstep; //必要ステップ数
  
  double changedelaytime = delaytime / (10 * steppercm); //1ステップあたりに変化させる時間

  delaytime = delaytime*1.1;

  for(long i=1;i<steps+1;i++){
    
    if((float)i * cmperstep < 11){
      delaytime -= changedelaytime;
    }
    if((float)i * cmperstep > movingdistance - 11){
      delaytime += changedelaytime;
    }
    
    digitalWrite(intopulse_pin,HIGH);
    delayMicroseconds(delaytime);
    digitalWrite(intopulse_pin,LOW);
    delayMicroseconds(delaytime);

  if(sensorcheck){
    //1cm進むごとにチェック
    if(rotdirection == 1){
      if(i%(int)steppercm == 0){
        Serial.print("check:");
        Serial.print(i);
        Serial.print(" ");
        Serial.println(PP1_US.echoCatch());
        
        while((int)PP1_US.echoCatch() < 70 ||(int)PP2_US.echoCatch() < 70){
          Serial.println("danger");
          delay(2000);
        }
      }
    }
  }
  
  return;
  }

}
*/
