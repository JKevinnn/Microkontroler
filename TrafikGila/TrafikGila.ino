#include <TM1637Display.h>
#define m1 22
#define k1 24
#define h1 26

#define m2 28
#define k2 30
#define h2 32

#define m3 34
#define k3 36
#define h3 38
#define clk1 2
#define dio1 3
#define clk2 4
#define dio2 5
#define clk3 6
#define dio3 7

TM1637Display display1 (2, 3);
TM1637Display display2 (4, 5);
TM1637Display display3 (6, 7);

int waktu1 = 5;
int waktu2 = 10;
int waktu3 = 10;

int kondisi = 1;
int kons = 1;

void setup() {
   display1.setBrightness(7);
   display2.setBrightness(7);
   display3.setBrightness(7);
   display1.clear();
   display2.clear();
   display3.clear();
  // put your setup code here, to run once:
  pinMode(m1, OUTPUT);
  pinMode(k1, OUTPUT);
  pinMode(h1, OUTPUT);

  pinMode(m2, OUTPUT);
  pinMode(k2, OUTPUT);
  pinMode(h2, OUTPUT);

  pinMode(m3, OUTPUT);
  pinMode(k3, OUTPUT);
  pinMode(h3, OUTPUT);

  digitalWrite (m1, LOW);
  digitalWrite (k1, LOW);
  digitalWrite (h1, LOW);

  digitalWrite (m2, HIGH);
  digitalWrite (k2, LOW);
  digitalWrite (h2, LOW);

  digitalWrite (m3, HIGH);
  digitalWrite (k3, LOW);
  digitalWrite (h3, LOW);
}

void loop() {
  display1.showNumberDec(waktu1, false);
  display2.showNumberDec(waktu2, false);
  display3.showNumberDec(waktu3, false);

  if (waktu1 <= 5 && kondisi == 1) {
  
    if (kons == 1) {
      digitalWrite (m1, LOW);
      delay(300);
      digitalWrite (k1, HIGH);
      delay(300);
      digitalWrite (k1, LOW);
      delay(300);
      kons = 2;
    }
    digitalWrite (h1, HIGH);
    if (waktu1 <= 0) {
      digitalWrite (h1, LOW);
      delay(300);
      digitalWrite (k1, HIGH);
      delay(300);
      digitalWrite (k1, LOW);
      delay(300);
      digitalWrite (m1, HIGH);
      kondisi =  2;
      waktu1 = 10;
      waktu2 = 5;
    }
  }
  if (waktu2 <= 5 && kondisi == 2) {
    if (kons == 2) {
      digitalWrite (m2, LOW);
      delay(300);
      digitalWrite (k2, HIGH);
      delay(300);
      digitalWrite (k2, LOW);
      delay(300);
      kons = 3;
    }
    digitalWrite (h2, HIGH);
    if (waktu2 <= 0) {
      digitalWrite (h2, LOW);
      delay(300);
      digitalWrite (k2, HIGH);
      delay(300);
      digitalWrite (k2, LOW);
      delay(300);
      digitalWrite (m2, HIGH);
      kondisi =  3;
      waktu2 = 10;
      waktu3 = 5;
    }
  }
  if (waktu3 <= 5 && kondisi == 3) {
    if (kons == 3) {
      digitalWrite (m3, LOW);
      delay(300);
      digitalWrite (k3, HIGH);
      delay(300);
      digitalWrite (k3, LOW);
      delay(300);
      kons = 1;
    }
    digitalWrite (h3, HIGH);
    if (waktu3 <= 0) {
      digitalWrite (h3, LOW);
      delay(300);
      digitalWrite (k3, HIGH);
      delay(300);
      digitalWrite (k3, LOW);
      delay(300);
      digitalWrite (m3, HIGH);
      kondisi =  1;
      waktu3 = 10;
      waktu1 = 5;
      return;
    }
  }

  delay(1000);
  waktu1--;
  waktu2--;
  waktu3--;
}
