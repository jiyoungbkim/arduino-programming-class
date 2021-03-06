#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  
  //센서의 초기값을 보정해주는 역할을 하는 함수
  mpu6050.calcGyroOffsets(true);
  
  //임의의 값을 줄 수도 있다.
  //mpu.6050.setGyroOffsets(x, y, z);
}

void loop() {
  mpu6050.update();
  Serial.print(" angleX : ");
  Serial.print(mpu6050.getAngleX());
  Serial.print(" angleY : ");
  Serial.print(mpu6050.getAngleY());
  Serial.print(" angleZ : ");
  Serial.print(mpu6050.getAngleZ());
  Serial.println();
  delay(1000);
}
