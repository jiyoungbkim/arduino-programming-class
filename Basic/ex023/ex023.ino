#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int trig_pin = 2;
int echo_pin = 3;
int light_pin = A0;
int red_btn = 13;
int blue_btn = 12;

void setup() {
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();

  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(red_btn, INPUT);
  pinMode(blue_btn, INPUT);
}

void loop() {
  Serial.println(red_btn);
  Serial.println(blue_btn);
  lcd.clear();
  lcd.home();
  
  red_btn = digitalRead(13);
  blue_btn = digitalRead(12);
  
  if(red_btn == HIGH) {
    lcd.print("light value : ");
    lcd.setCursor(0,1);
    lcd.print(getLight(light_pin));
    delay(1000);
  } else if(blue_btn == HIGH) {   
    lcd.print("distance value : ");
    lcd.setCursor(0,1);
    lcd.print(getDistance(trig_pin, echo_pin));
    delay(1000);
  } else {
    lcd.print("select button");
    delay(1000);
    /*1초 간격으로 루프를 도는데 루프중간에 버튼이 눌리면 
    동작을 안하기 때문에 버튼은 1초 이상 눌러주어야 한다.*/
  }
}
int getLight(int aLight_pin) {
  return analogRead(aLight_pin);
}
int getDistance(int aTrig_pin, int aEcho_pin) {
  digitalWrite(aTrig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(aTrig_pin, LOW);
  long duration = pulseIn(aEcho_pin, HIGH);
  long distance = duration/58.2;
  delay(100);
  return distance;
}
