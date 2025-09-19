#include <Keypad.h>
#include <TM1637Display.h>

// Pin TM1637
#define CLK 10
#define DIO 11

TM1637Display display(CLK, DIO);

// Konfigurasi keypad
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

void setup() {
  Serial.begin(9600);
  display.setBrightness(7);
  display.clear();
}

void loop() {
  char customKey = customKeypad.getKey();

  if (customKey) {
    Serial.println(customKey);

    switch (customKey) {
      case '0' ... '9':
        display.showNumberDec(customKey - '0');
        break;

      case 'A':
        display.setSegments((const uint8_t[]) {
          SEG_A | SEG_B | SEG_C | SEG_E | SEG_F | SEG_G}, 1, 3);
        break;
      case 'B':
        display.setSegments((const uint8_t[]) {SEG_C | SEG_D | SEG_E | SEG_F | SEG_G}, 1, 3);
        break;
      case 'C':
        display.setSegments((const uint8_t[]) {SEG_A | SEG_D | SEG_E | SEG_F}, 1, 3);
        break;
      case 'D':
        display.setSegments((const uint8_t[]){SEG_B | SEG_C | SEG_D | SEG_E | SEG_G}, 1, 3); 
        break;
        case '*':
        display.setSegments((const uint8_t[]){SEG_A | SEG_C | SEG_E | SEG_G}, 1, 3); 
        break;

      case '#':
        display.setSegments((const uint8_t[]){SEG_B | SEG_C | SEG_E | SEG_F| SEG_G}, 1, 3); 
        break;

      default:
        display.clear();
        break;
    }
  }
}
