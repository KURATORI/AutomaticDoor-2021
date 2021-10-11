#ifndef INCLUDE_MOTOR
#define INCLUDE_MOTOR

class Motor{
  private:
    int pin_outpulse;           //パルスによってモーターの回転量を制御するピン番号
    int pin_rotdirection;       //回転方向制御のピン番号
    int pin_inpulse;            //モーターから一定の回転によって送られてくるパルスのピン番号
    
    bool rotdirection;          //回転方向
    float rps;                 //モーターの回転速度[r/s]
    float meter;               //モーターで移動する距離
    
  public:
    Motor(int pin1, int pin2, int pin3);
    void rotateDirection(bool rotdirection);
    void motorSpeed(int rps); 
    
    // モーターの回転速度と方向を指定し、回す
    void rotateMotor(bool rotdirection, int rps, float meter);
    
};

#endif
