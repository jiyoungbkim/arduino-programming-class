// preprocessor 
#define C 262   // 도
#define D 294   // 레
#define E 330   // 미
#define F 349   // 파
#define G 392   // 솔
#define A 440   // 라
#define B 494   // 시
#define H 523   // 높은 도

int piezo = 8;
int notes[24] = { G,G,A,A,G,G,E,G,G,E,E,D,G,G,A,A,G,G,E,G,E,D,E,C};
int btn1 = 13;
int btn2 = 12;

void setup() {
  pinMode(piezo, OUTPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
}

void loop() {

  if(digitalRead(btn1) == HIGH) {
    for(int i = 0; i<12; i++) {
     tone(piezo, notes[i], 250);
     delay(400);
    }
  }
  if(digitalRead(btn2) == HIGH) {
    for(int i = 12; i<24; i++) {
     tone(piezo, notes[i], 250);
     delay(400);
    }
  }

}
