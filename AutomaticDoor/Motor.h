#ifndef INCLUDE_MOTOR
#define INCLUDE_MOTOR
  #ifndef INCLUDE_ARDUINO
  #define INCLUDE_ARDUINO
  #include <Arduino.h>
  #endif

  #ifndef INCLUDE_US
  #define INCLUDE_US
  #include "Usound.h"
  #endif


class Motor{
  private:
    int feedbackpulse_pin;    //モーターから一定の回転によって送られてくるパルスのピン番号
    int intopulse_pin_open;   //開く
    int intopulse_pin_close;  //閉まる
    
    bool rotdirection;          //回転方向 0で開く 1で閉まる
    float centimeter_per_sec;   //扉を移動させる速度[cm/s]
    float movingdistance;       //扉を移動させる距離[cm]
    float sensorcheck;          //trueでセンサをチェックするモードで運転

    Usound PP1_US;   //(PP1_ECHO_PIN, PP1_TRIG_PIN)
    Usound PP2_US;  //(PP2_ECHO_PIN, PP2_TRIG_PIN)
    
  public:
    Motor(int pin1, int pin2, int pin3);
    void setRotateDirection(bool rotdirection); //回転方向の設定
    void setSpeed(int centimeter_per_sec); //回転速度の設定
    
    // モーターの回転速度と方向を指定し、回す
    void rotate(bool rotdirection, float centimeter_per_sec, float movingdistance, bool sensorcheck);
    //void rotate_easing(bool rotdirection, float centimeter_per_sec, float movingdistance, bool sensorcheck, float easein, float easeout);
    void rotate();
    
};

#endif
