#include <TM1637Display.h>
int m = 0;
int d = 0;

#define CLK 6
#define DIO 7

#define A 2
#define B 3
#define C 4

bool syaratreset = false;

TM1637Display display(CLK, DIO);

void setup() {
  display.setBrightness(7);
  pinMode(A, INPUT);
  pinMode(B, INPUT);
  pinMode(C, INPUT);
}

void loop() {
  display.showNumberDec(m, true, 2, 0);
  display.showNumberDec(d, true, 2, 2);

  while (digitalRead(A) == HIGH) {
    for (m = 0; m < 60; m++) {
      display.showNumberDec(m, true, 2, 0);
      for (d = 0; d < 60; d++) {
        display.showNumberDec(d, true, 2, 2);
        delay(1000);

        // Tombol STOP
        if (digitalRead(B)) {
          syaratreset = true;
          while (digitalRead(B) == HIGH) {
            delay (10);
          }
        }
        if (syaratreset && digitalRead(C) == HIGH) {
          m = 0;
          d = 0;
          delay(100);
          display.showNumberDec(m, true, 2, 0);
          display.showNumberDec(d, true, 2, 2);
          return;
        }
      }
    }
  }
}
