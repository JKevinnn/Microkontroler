#include <LiquidCrystal.h>
#include <Keypad.h>
const byte ROWS = 4;
const byte COLS = 4;
int baris = 0;
int pengulangan = 0;

char hexaKeys[ROWS][COLS] = {
  {'D', 'C', 'B', 'A'},
  {'#', '9', '6', '3'},
  {'0', '8', '5', '2'},
  {'*', '7', '4', '1'}
};

byte rowPins[ROWS] = {37, 35, 33, 31};
byte colPins[COLS] = {45, 43, 41, 39};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);

}

void loop() {
  char input = customKeypad.getKey();
  if (input) {
    lcd.setCursor(pengulangan, baris);
    pengulangan++;
    if (baris == 0) {
      lcd.print(input);
      if (pengulangan > 15) {
        baris = 1;
        pengulangan = 0;
      }
    }
    if (baris == 1) {
      lcd.print(input);
      if (pengulangan > 15) {
        baris = 0;
        pengulangan = 0;
      }
    }
  }
}
