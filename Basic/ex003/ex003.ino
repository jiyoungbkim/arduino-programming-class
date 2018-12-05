void setup() {
  // put your setup code here, to run once:
}
void loop() {
  // put your main code here, to run repeatedly:
  /*analogWrite(9,0);
  delay(500);
  analogWrite(9,63);
  delay(500);
  analogWrite(9,127);
  delay(500);
  analogWrite(9,255);
  delay(500);
  analogWrite(9,127);
  delay(500);
  analogWrite(9, 63);
  delay(500);*/
  
  for(int i=0;i<=255;i++){
    analogWrite(9,i);
    delay(10);
  }
  for(int i=255;i>-1;i--){
    analogWrite(9,i);
    delay(10);
  }
}
