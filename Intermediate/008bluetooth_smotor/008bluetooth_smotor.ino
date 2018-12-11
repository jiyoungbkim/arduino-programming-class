#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial bluetooth(2, 3);
Servo myservo;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  myservo.attach(9);

}

void loop() {
  char val = bluetooth.read();

  if(bluetooth.available()) {
    Serial.write(bluetooth.read());
  }
  if(val == 'r') {
    for(int i=0; i < 180; i++) {
      myservo.write(i);
      delay(15);
    }
  }
  if(val == 'l') {
    for(int i=180; i > 0; i--) {
      myservo.write(i);
      delay(15);
    }  
  }


}
