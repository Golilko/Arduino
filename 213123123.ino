
#define a 5
#define b 6
#define c 7
#define d 8
#define e 9
#define f 10
#define g 11
#define dp 12

#define d1 A1
#define d2 A2
#define d3 A3
#define d4 A4

int n = 0;

void setup() {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);

  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void poop0() {
    pickDigit(0); // включаем первую цифру (тысячи)
    pickNumber(n/1000);
    delay(5);
}
void poop1() {
    pickDigit(1); // включаем вторую цифру (сотни)
    pickNumber((n % 1000) / 100);
    delay(5);
}
void poop2() {
    pickDigit(2); // включаем третью цифру (десятки)
    pickNumber(n % 100 / 10);
    delay(5);
}
void poop3() {
    pickDigit(3); // включаем четвертую цифру (единицы)
    pickNumber(n % 10);
    delay(5);    
}
void loop() {
  if (digitalRead(A0) == HIGH) {
    delay (500);
     n++;
    if (n == 10000) { 
      n = 0; 
      }
}
if (10 <= n) {
  poop2();
}
poop3();
}

// определение разряда
void pickDigit(int x) {
  for(int i = 1; i < 9; i++){
     digitalWrite(d4, HIGH);
  if (i == 10)
      i = 0;
  for(int j = 1; j < 9; j++){
     digitalWrite(d3, HIGH);
  if (j == 10)
      j = 0;
  for(int k = 1; k < 9; k++){
     digitalWrite(d2, HIGH);
  if (k == 10)
      k = 0;
  for(int l = 0; l < 9; l++){
    digitalWrite(d1, HIGH);
    if (l == 10)
      l = 0;
  }}}}
  Serial.println(x);
  switch (x) {
    case 0: digitalWrite(d1, LOW);  break;
    case 1: digitalWrite(d2, LOW);  break;
    case 2: digitalWrite(d3, LOW);  break;
    default: digitalWrite(d4, LOW); break;
  }
}

// определение символа (цифры)
void pickNumber(int count) {
  switch (count) {
    default: zero();   break;
    case 1: one();     break;
    case 2: two();     break;
    case 3: three();  break;
    case 4: four();    break;
    case 5: five();     break;
    case 6: six();       break;
    case 7: seven(); break;
    case 8: eight();  break;
    case 9: nine();   break;
  }
}

void zero() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

void one() {
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void two() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}

void three() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}

void four() {
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void five() {
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void six() {
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void seven() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void eight() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void nine() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}
