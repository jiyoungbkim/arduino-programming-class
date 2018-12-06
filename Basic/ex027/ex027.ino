#include <Servo.h> // 내장 라이브러리

Servo myservo;

void setup() {
  myservo.attach(9);
}

void loop() {
  for(int i = 0; i < 180; ++i)
  {
    myservo.write(i); // 움직이고 싶은 각도
    delay(15);
  }
  //myservo.write(0);
  //delay(1000);
  for(int i = 180; i >= 0; --i) {
    myservo.write(i);
    delay(15);
  }
}
