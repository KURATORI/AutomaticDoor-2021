#include"Motor.h"
  
Motor::Motor(int pin1, int pin2, int pin3){
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

  float cmperstep = 8/200; //(1周あたり)8cm/200ステップ
  float delaytime = 0.01*(cmperstep/movingdistance)/2; //1ステップでの移動距離/1ステップに掛かる時間 = 1ステップの移動速度
  float steps = movingdistance/cmperstep; //必要ステップ数
  for(int i=0;i<steps;i++){
    digitalWrite(intopulse_pin,HIGH);
    delay(delaytime);
    digitalWrite(intopulse_pin,LOW);
    delay(delaytime);
  }
  return;
}
