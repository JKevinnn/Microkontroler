#include <TM1637Display.h>

#define CLK 6
#define DIO 7
#define A 2  // Start
#define B 3  // Stop
#define C 4  // Reset

TM1637Display display(CLK, DIO);

int m = 0;
int d = 0;
bool running = false;

void setup() {
  display.setBrightness(7);
  pinMode(A, INPUT);
  pinMode(B, INPUT);
  pinMode(C, INPUT);
}

void loop() {
  if (digitalRead(A) == HIGH) {
    running = true;
  }

  if (digitalRead(B) == HIGH) {
    running = false;
  }

  if (!running && digitalRead(C) == HIGH) {
    m = 0;
    d = 0;
    display.showNumberDecEx(0, 0b11100000, true); 
    delay(500); // debounce
  }

  if (running) {
    display.showNumberDecEx(m * 100 + d, 0b11100000, true); 
    delay(10); // delay 1 detik
    d++;
    if (d >= 60) {
      d = 0;
      m++;
      if (m >= 60) {
        m = 0;
      }
    }
  }
}
