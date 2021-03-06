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

void setup() {
  pinMode(piezo, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for(int i = 0; i<12; i++) {
    Serial.println(analogRead(A0));
    tone(piezo, notes[i], analogRead(A0));
    delay(analogRead(A0));
  }
  for(int i = 12; i<24; i++) {
    Serial.println(analogRead(A0));
    tone(piezo, notes[i], analogRead(A0));
    delay(analogRead(A0));
  }

}
