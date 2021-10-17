#ifndef INCLUDE_USOUND
#define INCLUDE_USOUND

  #ifndef INCLUDE_ARDUINO
  #define INCLUDE_ARDUINO
  #include <Arduino.h>
  #endif
  
class Usound{
  private:
    int echo_pin; //超音波センサから受け取るピン
    int trig_pin; //超音波を出力するピン

    float duration = 0;
    float distance = 0;
    
  public:
    Usound(int pin1, int pin2);
    float echoCatch();   //距離を計測
  
};


#endif
