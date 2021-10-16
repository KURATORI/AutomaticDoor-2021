#ifndef INCLUDE_TEMPERATURE
#define INCLUDE_TEMPERATURE

  #ifndef ADAFRUIT_MLX90614
  #define ADAFRUIT_MLX90614
  #include"src/libraries/Adafruit_MLX90614_Library/Adafruit_MLX90614.h"

  
  #endif
  
class Temperature{
  private:
    float temperature_object=0;
    float temperature_ambient=0;
    
  public:
    
    Temperature();
    Adafruit_MLX90614 mlx;

    
    float getObjectTemperature();
    float getAmbientTemperature();
};

#endif
