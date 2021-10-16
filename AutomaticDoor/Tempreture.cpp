#include"Tempreture.h"

Tempreture::Tempreture(){
  mlx = Adafruit_MLX90614();
  tempreture_object = mlx.readObjectTempC();
  tempreture_ambient = mlx.readAmbientTempC();
}

float Tempreture::getObjectTempreture(){
  tempreture_object = mlx.readObjectTempC();
  return tempreture_object;
}

float Tempreture::getAmbientTempreture(){
  tempreture_ambient = mlx.readAmbientTempC();
  return tempreture_ambient;
}
