int pzo = 6; //틸트 핀 사용
int dly = 250;

void setup() {
  pinMode(pzo, OUTPUT);

}
void loop() {
  analogWrite(pzo, 64);//(핀번호,0~255)전압을 조절하여 소리 높낮이 조절
  delay(dly);
  analogWrite(pzo, 128);
  delay(dly);
  analogWrite(pzo, 255);
  delay(dly);
}
