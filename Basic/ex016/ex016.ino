int trig_pin = 2;
int echo_pin = 3;

void setup() {
  Serial.begin(9600);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
}
void loop() {
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  long duration = pulseIn(echo_pin, HIGH);// 에코핀 사이를 계산
  long distance = duration/58.2;// 음속을 2로 나눈 상수 58.2로 나눈다

  Serial.println(distance);
  delay(100);  
}
