#include <SoftwareSerial.h> //시리얼통신 라이브러리 호출

int blueTx = 2; //신호를 보내는 핀
int blueRx = 3; //신호를 받는 핀
SoftwareSerial mySerial(blueTx, blueRx); // 시리얼 통신을 위한 객체선언

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600); //블루투스 시리얼
}

void loop() {
  //블루트스 측 내용을 시리얼모니터에 출력
  if(mySerial.available()) {
    Serial.write(mySerial.read());
  }
  //시리얼 모니터 내용을 블루투스 측에 WRITE
  if(Serial.available()) {
    mySerial.write(Serial.read());
  }
}
