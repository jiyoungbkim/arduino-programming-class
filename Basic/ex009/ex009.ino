int melody[] = {262, 294, 330, 349, 392, 440, 494, 523};

void setup() {
  for(int i = 0; i<8; i++) {
    tone(8, melody[i], 250);
    delay(400);
    noTone(8);
  } 
  //도
  tone(8, melody[0], 250);
  delay(400);
  noTone(8);
  
  tone(8, melody[0], 250);
  delay(400);
  noTone(8);
  
  //솔
  tone(8, melody[4], 250);
  delay(400);
  noTone(8);

  tone(8, melody[4], 250);
  delay(400);
  noTone(8);
  
  //라
  tone(8, melody[5], 250);
  delay(400);
  noTone(8);

  tone(8, melody[5], 250);
  delay(400);
  noTone(8);

  tone(8, melody[4], 250);
  delay(400);
  noTone(8);
  
  //파
  tone(8, melody[3], 250);
  delay(400);
  noTone(8);

  tone(8, melody[3], 250);
  delay(400);
  noTone(8);
  
  //미
  tone(8, melody[2], 250);
  delay(400);
  noTone(8);

  tone(8, melody[2], 250);
  delay(400);
  noTone(8);

  tone(8, melody[1], 250);
  delay(400);
  noTone(8);

  tone(8, melody[0], 250);
  delay(400);
  noTone(8);
}

void loop() {
  
}
