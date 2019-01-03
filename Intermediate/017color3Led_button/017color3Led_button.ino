int r_pin = 9;
int g_pin = 10;
int b_pin = 11;
int btn_red = 2;
int btn_green = 4;
int btn_blue = 7;

void setup() {
  // anode type 3 color led
  pinMode(r_pin, OUTPUT);
  pinMode(g_pin, OUTPUT);
  pinMode(b_pin, OUTPUT);
  pinMode(btn_red, INPUT);
  pinMode(btn_green, INPUT);
  pinMode(btn_blue, INPUT); 
  delay(250);
}

void loop() {
  btn_red = digitalRead(2);
  btn_green = digitalRead(4);
  btn_blue = digitalRead(7);

  if(btn_red == HIGH) {
    digitalWrite(r_pin, LOW);
    delay(100);
  } else if (btn_green == HIGH) {
    digitalWrite(g_pin, LOW);
    delay(100);
  } else if (btn_blue == HIGH) {
    digitalWrite(b_pin, LOW);
    delay(100);
  } else {
    digitalWrite(r_pin, HIGH);
    digitalWrite(g_pin, HIGH);
    digitalWrite(b_pin, HIGH);
  }

}
