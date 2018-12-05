int trig_pin = 2;
int echo_pin = 3;

void setup() {
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
}

void loop() {
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  long duration = pulseIn(echo_pin, HIGH);

  long distance = duration/58.2;

  tone(8, 1000, 20);
  delay(20);
  noTone(8);

  delay(2*distance);

}
