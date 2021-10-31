#include"Motor.h"
  #ifndef INCLUDE_SENSORSTATUS
  #define INCLUDE_SENSORSTATUS
  #include"SensorStatus.h"
  #endif

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
    if(i%(int)period==0){
      Serial.println("check");
      Serial.println(i);
      Serial.println(SensorStatus::sensor_isSafe);
    }
    
  }
  return;
}
