#include <TM1637Display.h>

// Pin CLK dan DIO sesuai dengan koneksi ke Arduino
#define CLK 4
#define DIO 5

TM1637Display display(CLK, DIO);

void setup() {
  display.setBrightness(7); // Nilai 0–7, semakin tinggi semakin terang
}

void loop() {
    for (int i = 0; i < 10; i++) {
    display.showNumberDec(i);
    delay(500);
  }
  // Menampilkan angka mundur dari 9 ke 0
  for (int i = 9; i >= 0; i--) {
    display.showNumberDec(i);
    delay(500);
  }

  
  delay(500);
}
