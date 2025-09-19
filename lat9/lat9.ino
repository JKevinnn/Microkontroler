#include <TM1637Display.h>

// Pin CLK dan DIO sesuai dengan koneksi ke Arduino
#define CLK 4
#define DIO 5

TM1637Display display(CLK, DIO);

void setup() {
  display.setBrightness(1); // Nilai 0–7, semakin tinggi semakin terang
}

void loop() {
  // Menampilkan angka mundur dari 0 ke 9999
    for (int i = 0; i < 10000; i++) {
    display.showNumberDec(i,false);
    delay(1);
  }
  // Menampilkan angka mundur dari 9999 ke 0
  for (int i = 10000; i >= 0; i--) {
    display.showNumberDec(i,false);
    delay(1);
  }

  
  delay(500);
}
