#ifndef INCLUDE_MOTOR
#define INCLUDE_MOTOR
  #ifndef INCLUDE_ARDUINO
  #define INCLUDE_ARDUINO
  #include <Arduino.h>
  #endif

class Motor{
  private:
    int inpulse_pin;            //モーターから一定の回転によって送られてくるパルスのピン番号
    int rotdirection_pin;       //回転方向制御のピン番号
    int outpulse_pin;           //パルスによってモーターの回転量を制御するピン番号
    
    
    
    bool rotdirection;          //回転方向
    float rps;                 //モーターの回転速度[r/s]
    float meter;               //モーターで移動する距離
    
  public:
    Motor(int pin1, int pin2, int pin3);
    void rotateDirection(bool rotdirection); //回転方向の設定
    void motorSpeed(int rps); //回転速度の設定
    
    // モーターの回転速度と方向を指定し、回す
    void rotateMotor(bool rotdirection, int rps, float meter);
    
};

#endif
