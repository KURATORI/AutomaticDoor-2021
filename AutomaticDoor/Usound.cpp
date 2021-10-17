#include"Usound.h"

Usound::Usound(int pin1, int pin2){
  echo_pin = pin1;
  trig_pin = pin2;
}

float Usound::echoCatch(){
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  duration = pulseIn(trig_pin, LOW); //パルスが入力された際にその時間をμs単位で計測
  if(duration > 0){
    duration = duration / 2;
    distance = duration * 340 /1000000; //センサからの距離(mm)を代入
    return  distance;
  }
}
