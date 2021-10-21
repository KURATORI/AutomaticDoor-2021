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

  float cmperstep = (float)8/3200; //(1周あたり)8cm:3200ステップ
  double delaytime = cmperstep/centimeter_per_sec/2*1000*1000;//[μs]
  //double delaytime = (float)0.02/centimeter_per_sec*1000;
  double steps = movingdistance/cmperstep; //必要ステップ数

  long deltatime=0;
  for(long i=0;i<steps;i++){
   
   /*
    Serial.println(steps); 
    
    Serial.print(" rotdirection: ");
    Serial.println(this->rotdirection);

    Serial.print(cmperstep);
    Serial.print(" cmperstep: ");

    Serial.print(" delaytime: ");
    Serial.print(delaytime);
    
    Serial.print("Needstep: ");
    Serial.println(steps);

    Serial.print(" step: ");
    Serial.println(i);
    
    Serial.print(" moved[cm]: ");
    
    Serial.print(i*cmperstep);

    Serial.print(" deltatime: ");
    deltatime+=delaytime*2;
    Serial.println(deltatime);
    */
    
    digitalWrite(intopulse_pin,HIGH);
    delayMicroseconds(delaytime);
    //delay(delaytime);
    digitalWrite(intopulse_pin,LOW);
    delayMicroseconds(delaytime);
    //delay(delaytime);
    
  }
  return;
}
