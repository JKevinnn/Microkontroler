#include <TM1637Display.h>
  int j = 0;
  int i = 0;
// Pin CLK dan DIO sesuai dengan koneksi ke Arduino
#define CLK 4
#define DIO 5

TM1637Display display(CLK, DIO);

void setup() {
  display.setBrightness(1); // Nilai 0–7, semakin tinggi semakin terang
}

void loop() {
  for (j = 0; j < 24; j++) {
    display.showNumberDec(j, true, 2, 0);
    delay(10);
    for (i = 0; i < 60; i++) {
      display.showNumberDec(i, true, 2, 2);
      delay(60000);
    }
  }
}
