#include"Motor.h"
  
Motor::Motor(int pin1, int pin2, int pin3){
  inpulse_pin = pin3;
  rotdirection_pin = pin2;
  outpulse_pin = pin1;
   
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
  
  digitalWrite(rotdirection_pin, rotdirection);

  long temp = 0;
  while(true){
    if(digitalRead(inpulse_pin)){
      temp++;
      if(inpulsetime < temp){
        finished = true;        
      }
    }

    //1回転1.8°
    if(count < outpulsetime && !finished){
      digitalWrite(outpulse_pin,HIGH);
      delay(delaytime);
      digitalWrite(outpulse_pin,LOW);
      delay(delaytime);
      }
    count++;
  }
}
