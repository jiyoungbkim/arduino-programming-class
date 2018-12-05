int trig_pin = 2;
int echo_pin = 3;
int red_led = 13;
int green_led = 12;
int red_btn = 7;
int green_btn = 4;

void setup() {
  Serial.begin(9600);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(red_btn, INPUT);
  pinMode(green_btn, INPUT);
}

void loop() {
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  long duration = pulseIn(echo_pin, HIGH);
  long distance = duration/58.2;
  Serial.println(distance);

  delay(100);

  if(distance >= 5 && distance <10) {
    if(digitalRead(green_btn) == HIGH) {
      digitalWrite(green_led, HIGH);
    } else {
      digitalWrite(green_led, LOW);
    }
  } else {
    if(digitalRead(red_btn) == HIGH) {
      digitalWrite(red_led, HIGH);
    } else {
      digitalWrite(red_led, LOW);
    }
  } 
  
}
