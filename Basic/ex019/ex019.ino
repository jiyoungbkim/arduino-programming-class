#include <Wire.h> //I2C와 통신하기 위한 라이브러리
#include <LiquidCrystal_I2C.h> //lcd 외부 라이브러리

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.begin(); //lcd 초기화

  lcd.backlight(); //백라이트 켜기
  lcd.print("ABCDEFGHIJKLMNOPQRSTUVWXYZ12345678901234"); //40개  
}

void loop() {  
  lcd.scrollDisplayLeft(); //왼쪽으로 스크롤
  delay(400);
}
