#include"Motor.h"
  
Motor::Motor(int pin1, int pin2, int pin3){
  pin_outpulse = pin1;
  pin_rotdirection = pin2;
  pin_inpulse = pin3; 
}

void Motor::rotateDirection(bool rotdirection){
  this->rotdirection = rotdirection;
  return;
}

void Motor::motorSpeed(int rps){
  this->rps = rps;
  return;
}

void Motor::rotateMotor(bool rotdirection, int rps, float meter){
  
  float delaytime = 5/rps;        //delaytimeミリ秒の間隔でパルスを出す
  long count = 0;
  bool finished = false; 
  long inpulsetime = 999999;              //meterから求められるはずだが今はよくわからない
  long outpulsetime = 999999;              //meterから求められるはずだが今はよくわからない  
  
  digitalWrite(pin_rotdirection, rotdirection);

  long temp = 0;
  while(true){
    if(digitalRead(pin_inpulse)){
      temp++;
      if(inpulsetime < temp){
        finished = true;        
      }
    }
    
    if(count < outpulsetime && !finished){
      digitalWrite(pin_outpulse,HIGH);
      delay(delaytime);
      digitalWrite(pin_outpulse,LOW);
      delay(delaytime);
      }
    count++;
  }
}
