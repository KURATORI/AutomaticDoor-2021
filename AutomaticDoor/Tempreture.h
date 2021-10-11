#ifndef INCLUDE_TEMPRETURE
#define INCLUDE_TEMPRETURE

  #ifndef ADAFRUIT_MLX90614
  #define ADAFRUIT_MLX90614
  #include<Adafruit_MLX90614.h>
  #endif
  
class Tempreture{
  private:
    Adafruit_MLX90614 mlx;
    float tempreture_object;
    float tempreture_ambient;
    
  public:
    Tempreture();
    float getObjectTempreture();
    float getAmbientTempreture();
};

#endif
