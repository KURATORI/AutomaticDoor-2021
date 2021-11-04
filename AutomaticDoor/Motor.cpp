#include"Motor.h"
  #ifndef INCLUDE_USOUND
  #define INCLUDE_USOUND
  #include"Usound.h"
  #endif

Motor::Motor(int pin1, int pin2, int pin3)
: PP1_US(7,8),PP2_US(9,10){
  feedbackpulse_pin = pin1;    
  rotdirection_pin = pin2; 
  intopulse_pin = pin3;        
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

void Motor::rotate(bool rotdirection, float centimeter_per_sec, float movingdistance){

  this->rotdirection = rotdirection;
  this->centimeter_per_sec = centimeter_per_sec;
  this->movingdistance = movingdistance;  //ドア幅に合わせるなら80cmぐらい？

  digitalWrite(rotdirection_pin,this->rotdirection);

  float cmperstep = (float)8/3200; //(1周あたり)8cm:3200ステップ
  double delaytime = cmperstep/centimeter_per_sec/2*1000*1000;//[μs]
  //double delaytime = (float)0.02/centimeter_per_sec*1000;//[ms]
  double steps = movingdistance/cmperstep; //必要ステップ数

  float period = (float)1/cmperstep;

  for(long i=0;i<steps;i++){
    digitalWrite(intopulse_pin,HIGH);
    delayMicroseconds(delaytime);
    digitalWrite(intopulse_pin,LOW);
    delayMicroseconds(delaytime);

    //1cm進むごとにチェック
    if(rotdirection == 1){
       if(i%(int)period == 0){
          Serial.print("check:");
          Serial.print(i);
          Serial.print(" ");
          Serial.println(PP1_US.echoCatch());
          if((int)PP1_US.echoCatch() < 70/*||(int)PP2_US.echoCatch() < 70*/){
            Serial.println("danger");
            delay(5000);
        }
      }
    }
  }
  return;
}
