int pin_in1 = 5;
int pin_in2 = 6;
int pin_speed = 3;
int btn_weakness = 12;
int btn_strength = 13;

void setup() {
  pinMode(pin_in1, OUTPUT);
  pinMode(pin_in2, OUTPUT);
  pinMode(pin_speed, OUTPUT);
  pinMode(btn_weakness, INPUT);
  pinMode(btn_strength, INPUT);
  Serial.begin(9600);
 }

void loop() {
  // 시계방향으로 회전
  btn_weakness = digitalRead(12);
  btn_strength = digitalRead(13);

  digitalWrite(pin_in1, HIGH);
  digitalWrite(pin_in2, LOW);

  if(btn_weakness == HIGH){
    digitalWrite(btn_strength, LOW);
    analogWrite(pin_speed, 255);
    delay(3000);
  } 
  if(btn_strength == HIGH) {
    digitalWrite(btn_weakness, LOW);
    analogWrite(pin_speed, 100);
    delay(3000);
  } 
  
   
}
