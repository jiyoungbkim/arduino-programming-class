#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial bluetooth(2, 3);

int posX = 0;
int posY = 0;

void setup() {
  lcd.begin();
  lcd.backlight();

  lcd.print("(^o^)");

  Serial.begin(9600);
  bluetooth.begin(9600);

  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

}

void loop() {
  char val = bluetooth.read();

  if(bluetooth.available()) {
    Serial.write(bluetooth.read());
  }
  if(val == 'r') {    
    lcd.clear();
    posX++;
    if(posX > 11) {
      posX = 0;
    }
    lcd.setCursor(posX, posY);
    lcd.print("(^o^)");
    digitalWrite(8, HIGH);
    digitalWrite(7, LOW);

  }
  if(val == 'l') {
    lcd.clear();
    posX--;
    if(posX < 0) {
      posX = 11;
    }
    lcd.setCursor(posX, posY);
    lcd.print("(^o^)");
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
  }
  if(val == 'u') {
    lcd.clear();
    posY = 0;
    lcd.setCursor(posX, posY);
    lcd.print("(^o^)");    
  }
  if(val =='d') {
    lcd.clear();
    posY = 1;
    lcd.setCursor(posX, posY);
    lcd.print("(^V^)");
  }


}
