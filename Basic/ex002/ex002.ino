int a;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, INPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
a = digitalRead(13);
  if(a==HIGH) {
    Serial.println("a is High");
  } else {
    Serial.println("a is Low");
  }
  delay(500); 
}
