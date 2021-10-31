#ifndef INCLUDE_SENSORSTATUS
#define INCLUDE_SENSORSTATUS

    #ifndef INCLUDE_ARDUINO
    #define INCLUDE_ARDUINO
    #include <Arduino.h>
    #endif

class SensorStatus{
    private:
        static byte sensor_isSafe;

    public:
        SensorStatus();
        static byte read_isSafe();
        static void update_isSafe(int bit, bool isSafe);
};

#endif