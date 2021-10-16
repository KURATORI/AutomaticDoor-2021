#ifndef INCLUDE_TEMPRETURE
#define INCLUDE_TEMPRETURE

  #ifndef ADAFRUIT_MLX90614
  #define ADAFRUIT_MLX90614
  #include"src/libraries/Adafruit_MLX90614_Library/Adafruit_MLX90614.h"

  
  #endif
  
class Tempreture{
  private:
    float tempreture_object=0;
    float tempreture_ambient=0;
    
  public:
    
    Tempreture();
    Adafruit_MLX90614 mlx;

    
    float getObjectTempreture();
    float getAmbientTempreture();
};

#endif
