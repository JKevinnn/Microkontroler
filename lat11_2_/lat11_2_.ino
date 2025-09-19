#include <Keypad.h>
#include <TM1637Display.h>

#define CLK 10
#define DIO 11

TM1637Display display(CLK, DIO);

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'D', 'C', 'B', 'A'},
  {'#', '9', '6', '3'},
  {'0', '8', '5', '2'},
  {'*', '7', '4', '1'}
};

byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {9, 8, 7, 6};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

// Buffer untuk menyimpan 4 karakter input
char inputBuffer[4] = {' ', ' ', ' ', ' '};
int inputIndex = 0;

void setup() {
  Serial.begin(9600);
  display.setBrightness(7);
  display.clear();
}

void loop() {
  char customKey = customKeypad.getKey();

  if (customKey) {
    Serial.println(customKey);

    if (inputIndex < 4 && ((customKey >= '0' && customKey <= '9') || (customKey >= 'A' && customKey <= 'D') || customKey == '*' || customKey == '#')) {
      inputBuffer[inputIndex] = customKey;
      inputIndex++;

      // Tampilkan buffer
      uint8_t segments[4];
      for (int i = 0; i < 4; i++) {
        segments[i] = encodeChar(inputBuffer[i]);
      }
      display.setSegments(segments);
    }

    /*Tombol reset
    if (customKey == '*') {
      inputIndex = 0;
      for (int i = 0; i < 4; i++) inputBuffer[i] = ' ';
      display.clear();
    }*/
  }
}

// Fungsi untuk mengonversi karakter ke 7-segment
uint8_t encodeChar(char c) {
  switch (c) {
    case '0'...'9': return display.encodeDigit(c - '0');
    case 'A': return SEG_A | SEG_B | SEG_C | SEG_E | SEG_F | SEG_G;
    case 'B': return SEG_C | SEG_D | SEG_E | SEG_F | SEG_G;
    case 'C': return SEG_A | SEG_D | SEG_E | SEG_F;
    case 'D': return SEG_B | SEG_C | SEG_D | SEG_E | SEG_G; 
    case '#': return SEG_B | SEG_C | SEG_E | SEG_F | SEG_G;
    case '*': return SEG_A | SEG_C | SEG_E | SEG_G; 
    case ' ': return 0x00;
    default: return 0x00; // Kosongkan jika tidak dikenali
  }
}
