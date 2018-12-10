#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <dht11.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int DHT11PIN = A0;
dht11 DHT11;

void setup() {
  lcd.begin();
  lcd.backlight();  
}

void loop() {
  int chk = DHT11.read(DHT11PIN);

  float index;
  float temp = DHT11.temperature;
  float humid = DHT11.humidity;
  index = 1.8*temp-0.55*(1-humid/100)*(1.8*temp-26)+32;

  lcd.setCursor(0, 0);
  lcd.print(humid, 1);
  lcd.print("% ");

  lcd.print(temp, 1);
  lcd.print("C");
  lcd.setCursor(0, 1);

  //lcd.print("index:");
  
  if(index >= 80) {  
    lcd.print(index, 1);
    lcd.print(" : VERY HIGH: ");   
  } else if(index >= 75 && index <80) {
    lcd.print(index, 1);
    lcd.print(" : HIGH ");    
  } else if(index >= 68 && index <75) {
    lcd.print(index, 1);
    lcd.print(" : NORMAL");    
  } else {
    lcd.print(index, 1);
    lcd.print(" : LOW");    
  }
  delay(100);
  

}
