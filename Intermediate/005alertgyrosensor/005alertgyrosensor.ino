#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);
int y_angle;

#define C 262   // 도
#define D 294   // 레
#define E 330   // 미
#define F 349   // 파
#define G 392   // 솔
#define A 440   // 라
#define B 494   // 시
#define H 523   // 높은 도

int piezo = 8;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  pinMode(piezo, OUTPUT);
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
  delay(500);

  y_angle = mpu6050.getAngleY();

  
  if(mpu6050.getAngleX() > 45 || mpu6050.getAngleX() < -45) {
    tone(piezo, C, 250);
    delay(200);
  }
  //절대값으로
  if(abs(y_angle) > 45) {
    tone(piezo, F, 250);
    delay(200);
  }
  if(mpu6050.getAngleZ() > 45 || mpu6050.getAngleZ() < -45) {
    tone(piezo, B, 250);
    delay(200);  
  }  

}
