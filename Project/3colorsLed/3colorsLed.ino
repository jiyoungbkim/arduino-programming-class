//74hc595 RegisterPins number 0-95 individual control, melody

int SER_Pin = 8;   //pin 14 on the 75HC595
int RCLK_Pin = 9;  //pin 12 on the 75HC595
int SRCLK_Pin = 10; //pin 11 on the 75HC595

//How many of the shift registers - change this
#define number_of_74hc595s 12 

//do not touch
#define numOfRegisterPins number_of_74hc595s * 8

boolean registers[numOfRegisterPins];

void setup(){
  pinMode(SER_Pin, OUTPUT);
  pinMode(RCLK_Pin, OUTPUT);
  pinMode(SRCLK_Pin, OUTPUT);

  // 모든 레지스터 핀을 리셋한다
  clearRegisters();
  writeRegisters();
}

//set all register pins to LOW
void clearRegisters(){
  for(int i = numOfRegisterPins - 1; i >=  0; i--){
     registers[i] = HIGH;
  }
}
//Set and display registers
//Only call AFTER all values are set how you would like (slow otherwise)
void writeRegisters(){

  digitalWrite(RCLK_Pin, LOW);

  for(int i = numOfRegisterPins - 1; i >=  0; i--){
    digitalWrite(SRCLK_Pin, LOW);

    int val = registers[i];

    digitalWrite(SER_Pin, val);
    digitalWrite(SRCLK_Pin, HIGH);

  }
  digitalWrite(RCLK_Pin, HIGH);

}

//set an individual pin HIGH or LOW
void setRegisterPin(int index, int value){
  registers[index] = value;
} 

void loop() {

  while(true){
    setColor1(0, 0, 0); 
    writeRegisters();
    delay(300);

    setColor2(0, 0, 0); 
    writeRegisters();
    delay(300);

    setColor3(0, 0, 0); 
    writeRegisters();
    delay(300);

    setColor4(0, 0, 0); 
    writeRegisters();
    delay(300);

    setColor5(0, 0, 0); 
    writeRegisters();
    delay(300);

    setColor1(0,1,0);
    writeRegisters();
    delay(200);
    setColor2(1,0,0);
    writeRegisters();
    delay(200);
    setColor3(0,0,1);
    writeRegisters();
    delay(200);
    setColor4(0,1,0);
    writeRegisters();
    delay(200);
    setColor5(1,0,0);
    writeRegisters();
    delay(200);
    setColor1(0,0,1);
    writeRegisters();
    delay(200);
    setColor2(0,1,0);
    writeRegisters();
    delay(200);
    setColor3(1,0,0);
    writeRegisters();
    delay(200);
    setColor4(0,0,1);
    writeRegisters();
    delay(200);
    setColor5(0,1,0);
    writeRegisters();
    delay(200); 
    setColor1(1,0,0);
    writeRegisters();
    delay(200);
    setColor2(0,0,1);
    writeRegisters();
    delay(200);
    setColor3(0,1,0);
    writeRegisters();
    delay(200);
    setColor4(1,0,0);
    writeRegisters();
    delay(200);
    setColor5(0,0,1);
    writeRegisters();
    delay(200);

  /*{
  setRegisterPin(4, 0);
  writeRegisters();
  delay(100);
  setRegisterPin(4, 1);
  }
  delay(100);*/

  /*{
  setColor1(0, 1, 1);
  writeRegisters();
  delay(300);
  setColor1(1, 1, 1);
  writeRegisters();
  }
  delay(300);*/
  }
}
void setColor1(int red, int green, int blue) {
  setRegisterPin(0, red);
  setRegisterPin(1, green);
  setRegisterPin(2, blue);

}
void setColor2(int red, int green, int blue) {
  setRegisterPin(4, red);
  setRegisterPin(5, green);
  setRegisterPin(6, blue);
}
void setColor3(int red, int green, int blue) {
  setRegisterPin(8, red);
  setRegisterPin(9, green);
  setRegisterPin(10, blue);
}
void setColor4(int red, int green, int blue) {
  setRegisterPin(13, red);
  setRegisterPin(14, green);
  setRegisterPin(15, blue);
}
void setColor5(int red, int green, int blue) {
  setRegisterPin(16, red);
  setRegisterPin(17, green);
  setRegisterPin(18, blue);
}
