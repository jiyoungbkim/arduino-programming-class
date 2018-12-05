void setup() {
}

void loop() {
  int light = analogRead(A0);
  //값의 범위를 맵핑 매개변수map(기존값, 센서최소값, 센서최대값,
  //(센서 최소값에 매칭되는)출력최대값, 출력최소값)
  int ledLight = map(light, 0, 900, 255, 0);
  analogWrite(9, ledLight);
  delay(500);
}
