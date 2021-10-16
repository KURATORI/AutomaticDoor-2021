#include"Temperature.h"

Temperature::Temperature(){
  mlx = Adafruit_MLX90614();
  temperature_object = mlx.readObjectTempC();
  temperature_ambient = mlx.readAmbientTempC();
}

float Temperature::getObjectTemperature(){
  temperature_object = mlx.readObjectTempC();
  return temperature_object;
}

float Temperature::getAmbientTemperature(){
  temperature_ambient = mlx.readAmbientTempC();
  return temperature_ambient;
}
