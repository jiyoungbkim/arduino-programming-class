int a_pin = 3;    // segment의 a led
int b_pin = 7;    // segment의 b led
int c_pin = A2;   // segment의 c led
int d_pin = A4;   // segment의 d led
int e_pin = A5;   // segment의 e led
int f_pin = 4;    // segment의 f led
int g_pin = A1;   // segment의 g led
int dp_pin = A3;    // segment의 dp led

int dig1 = 2;   // 좌측 기준으로 첫번째 segment
int dig2 = 5;   // 좌측 기준으로 두번째 segment
int dig3 = 6;   // 좌측 기준으로 세번째 segment
int dig4 = A0;   // 좌측 기준으로 번째 segment

// 숫자표시 배열
byte digits[10][7] = {
  //{A, B, C, D, E, F, G}
  {1,1,1,1,1,1,0},  // 0
  {0,1,1,0,0,0,0},  // 1
  {1,1,0,1,1,0,1},  // 2
  {1,1,1,1,0,0,1},  // 3
  {0,1,1,0,0,1,1},  // 4
  {1,0,1,1,0,1,1},  // 5
  {1,0,1,1,1,1,1},  // 6
  {1,1,1,0,0,0,0},  // 7
  {1,1,1,1,1,1,1},  // 8
  {1,1,1,1,0,1,1}   // 9
};
// 자리선택을 위한 배열
int digitPos[4] = {dig1, dig2, dig3, dig4};

int val = 0;
int val4 = 0;
int val3 = 0;
int val2 = 0;
int val1 = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(dig1, OUTPUT);
  pinMode(dig2, OUTPUT);
  pinMode(dig3, OUTPUT);
  pinMode(dig4, OUTPUT);
  
  pinMode(a_pin, OUTPUT);
  pinMode(b_pin, OUTPUT);
  pinMode(c_pin, OUTPUT);
  pinMode(d_pin, OUTPUT);
  pinMode(e_pin, OUTPUT);
  pinMode(f_pin, OUTPUT);
  pinMode(g_pin, OUTPUT);
  
  pinMode(dp_pin, OUTPUT);
}

void loop() {
  // 숫자의 자릿수를 구하기 위한 계산. 몫과 나머지이용
  val = millis() / 1000;

  val4 = (val / 1000) % 10;
  val3 = (val / 100) % 10;
  val2 = (val / 10) % 10;
  val1 = val % 10;

  if (val >= 1000)
  {
    clearAll();
    selectDigitPos(1);
    printNumber(val4);
    delayMicroseconds(1000);
  }

  if (val >= 100)
  {
    clearAll();
    selectDigitPos(2);
    printNumber(val3);
    delayMicroseconds(1000);
  }

  if (val >= 10)
  {
    clearAll();
    selectDigitPos(3);
    printNumber(val2);
    delayMicroseconds(1000);
  }

  if (val >= 0)
  {
    clearAll();
    selectDigitPos(4);
    printNumber(val1);
    delayMicroseconds(1000);
  }  
}

void selectDigitPos(int pos) {
  // HIGH로 전체 자리 신호를 끈다
  digitalWrite(dig1, HIGH);
  digitalWrite(dig2, HIGH);
  digitalWrite(dig3, HIGH);
  digitalWrite(dig4, HIGH);
  // 인덱스 번호를 구하기 위해 1을 빼준다
  digitalWrite(digitPos[pos-1], LOW);
}

// 숫자 출력을 위한 함수
void printNumber(int number) {
  digitalWrite(a_pin, digits[number][0]);
  digitalWrite(b_pin, digits[number][1]);
  digitalWrite(c_pin, digits[number][2]);
  digitalWrite(d_pin, digits[number][3]);
  digitalWrite(e_pin, digits[number][4]);
  digitalWrite(f_pin, digits[number][5]);
  digitalWrite(g_pin, digits[number][6]);
}
/*byte digits[10][7] = {
  //{A, B, C, D, E, F, G}
  {1,1,1,1,1,1,0},  // 0
  {0,1,1,0,0,0,0},  // 1
  {1,1,0,1,1,0,1},  // 2
  {1,1,1,1,0,0,1},  // 3
  {0,1,1,0,0,1,1},  // 4
  {1,0,1,1,0,1,1},  // 5
  {1,0,1,1,1,1,1},  // 6
  {1,1,1,0,0,0,0},  // 7
  {1,1,1,1,1,1,1},  // 8
  {1,1,1,1,0,1,1}   // 9
};
1을 출력한다고 했을 때
  digitalWrite(a_pin, digits[1][0]); //(a_pin,0)
  digitalWrite(b_pin, digits[1][1]); //(b_pin,1)
  digitalWrite(c_pin, digits[1][2]); //(c_pin,1)
  digitalWrite(d_pin, digits[1][3]); //(d_pin,0)
  digitalWrite(e_pin, digits[1][4]); //(e_pin,0)
  digitalWrite(f_pin, digits[1][5]); //(f_pin,0)
  digitalWrite(g_pin, digits[1][6]); //(g_pin,0)*/

// 출력을 초기화
void clearAll() {
  digitalWrite(a_pin, LOW);
  digitalWrite(b_pin, LOW);
  digitalWrite(c_pin, LOW);
  digitalWrite(d_pin, LOW);
  digitalWrite(e_pin, LOW);
  digitalWrite(f_pin, LOW);
  digitalWrite(g_pin, LOW);
  
  digitalWrite(dp_pin, LOW);
}

void printDP() {
  digitalWrite(dp_pin, HIGH);
}
