#include <Servo.h>

Servo myservo;

void setup() {
  myservo.attach(9);
  pinMode(13, INPUT);
}
void loop() {
  int val = analogRead(A0);
  //(가변저항의 최소값, 최대값, 각도0, 각도180)
  int rad = map(val, 0, 1023, 0, 180);

  if(digitalWrite(13) == HIGH) {
    myservo.write(rad);
    delay(15);//서브모터가 이동할 시간
  }
  
}
