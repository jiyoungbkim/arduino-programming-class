#include <Wire.h> //I2C와 통신하기 위한 라이브러리
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.begin();
  lcd.backlight();  
}

void loop() {
  int light = analogRead(A0);
  Serial.println(light);

  lcd.clear(); //수치가 1000자리가 넘어가면 에러가나기 떄문에 초기화
  lcd.print("light value : ");
  lcd.setCursor(0,1);
  lcd.print(light);

  delay(1000);
}
