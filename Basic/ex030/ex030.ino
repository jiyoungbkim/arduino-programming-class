int sound_pin = A0;
int led_green = 11;
int led_yellow = 10;
int led_red = 9;

int count = 0;

void setup() {
  Serial.begin(9600);
  pinMode(led_green, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(led_red, OUTPUT);
}

void loop() {
  int sound_value = analogRead(sound_pin);
  int light_value = map(sound_value, 0, 1023, 0, 255);
  
  Serial.print("sound value : ");
  Serial.println(sound_value);
  
  if(sound_value == 1023) {
    count++;
  }
  Serial.print("count : ");
  Serial.println(count);
  
    if(count >= 0 && count < 5) {
      analogWrite(led_green, light_value);
    } 
    else if(count >= 5 && count < 10) {
      analogWrite(led_yellow, light_value);
    }
    else if(count >= 10 && count < 15) {
      analogWrite(led_red, light_value);
    }

    delay(100);
}
