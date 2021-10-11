#include"Tempreture.h"

Tempreture::Tempreture(){
  mlx = Adafruit_MLX90614();
  tempreture_object = mlx.readObjectTempC();
  tempreture_ambient = mlx.readAmbientTempC();
}

float Tempreture::getObjectTempreture(){
  return tempreture_object;
}

float Tempreture::getAmbientTempreture(){
  return tempreture_ambient;
}
