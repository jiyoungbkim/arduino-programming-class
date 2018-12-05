int btnRed;
int btnYellow;
int btnGreen;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, INPUT);
  pinMode(4, INPUT);
  pinMode(2, INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  btnRed= digitalRead(7);
  btnYellow= digitalRead(4);
  btnGreen= digitalRead(2);

  Serial.print("r : ");
  Serial.println(btnRed);
  Serial.print("y : ");
  Serial.println(btnYellow);
  Serial.print("g : ");
  Serial.println(btnGreen);

  delay(100);
  
  if(btnRed==HIGH){
    digitalWrite(13,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(8,LOW);
  } 
  if(btnYellow==HIGH){
    digitalWrite(13,LOW);
    digitalWrite(12,HIGH); 
    digitalWrite(8,LOW);    
  } 
  if(btnGreen==HIGH){
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(8,HIGH);
  }
}
