# 温度測定クラス Tempreture

## メンバ変数

- `float tempreture_object`&nbsp;&nbsp;：物体の温度  
- `float tempreture_ambient`：周囲全体の温度  

## メンバ関数

- `Tempreture()` &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;：`tempreture_object`と`tempreture_ambient`に温度センサで読み取った値を入れる  
- `float getObjectTempreture()` &nbsp;：`tempreture_object`に温度センサで読み取った値を入れて、値を返却  
- `float getAmbientTempreture()`：`tempreture_ambient`に温度センサで読み取った値を入れて、値を返却  
