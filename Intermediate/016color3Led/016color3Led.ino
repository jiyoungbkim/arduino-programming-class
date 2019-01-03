int r_pin = 9;
int g_pin = 10;
int b_pin = 11;

void setup() {
  // anode type 3 color led
  analogWrite(r_pin, 255);
  analogWrite(g_pin, 255);
  analogWrite(b_pin, 255);
  delay(250);
}

void loop() {
  for(int i = 255; i > -1; i=i-10) {
    analogWrite(r_pin, i);
    delay(250);
  }
  analogWrite(r_pin, 255);

  for(int i = 255; i > -1; i=i-10) {
    analogWrite(g_pin, i);
    delay(250);
  }
  analogWrite(g_pin, 255);

    for(int i = 255; i > -1; i=i-10) {
    analogWrite(b_pin, i);
    delay(250);
  }
  analogWrite(b_pin, 255);



}
