#include"SensorStatus.h"

byte SensorStatus::sensor_isSafe = B00000000;

SensorStatus::SensorStatus(){

}

byte SensorStatus::read_isSafe(){
    return SensorStatus::sensor_isSafe;
}

void SensorStatus::update_isSafe(int bit, bool isSafe){
    bitWrite(SensorStatus::sensor_isSafe, bit, isSafe);
}