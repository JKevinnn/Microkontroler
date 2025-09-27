#include <LiquidCrystal.h>
#include <Keypad.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const byte ROW_NUM = 4;
const byte COLUMN_NUM = 4;

char keys[ROW_NUM][COLUMN_NUM] = {
  {'/', '*', '-', '+'},
  {'=', '9', '6', '3'},
  {'0', '8', '5', '2'},
  {'C', '7', '4', '1'}
};

byte pin_rows[ROW_NUM] = {37, 35, 33, 31};
byte pin_column[COLUMN_NUM] = {45, 43, 41, 39};

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);

String input = "";
float num1 = 0, num2 = 0;
char op = '\0';
bool operatorSet = false;
bool resultShown = false;

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("ITS KALKULATOR TIME");
  delay(1500);
  lcd.clear();
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    if (resultShown && key != 'C') {
      // Reset if user starts new input after result
      input = "";
      num1 = num2 = 0;
      op = '\0';
      operatorSet = false;
      resultShown = false;
      lcd.clear();
    }

    if (key >= '0' && key <= '9') {
      input += key;
    } else if (key == '+' || key == '-' || key == '*' || key == '/') {
      if (!operatorSet && input.length() > 0) {
        num1 = input.toFloat();
        op = key;
        input += key;
        operatorSet = true;
      }
    } else if (key == '=') {
      if (operatorSet) {
        int opIndex = input.indexOf(op);
        String secondPart = input.substring(opIndex + 1);
        num2 = secondPart.toFloat();

        float result = 0;
        switch (op) {
          case '+': result = num1 + num2; break;
          case '-': result = num1 - num2; break;
          case '*': result = num1 * num2; break;
          case '/': result = (num2 != 0) ? num1 / num2 : 0; break;
        }

        lcd.setCursor(0, 1);
        lcd.print(input);
        lcd.print(" = ");
        lcd.print(result);
        resultShown = true;
        return;
      }
    } else if (key == 'C') {
      input = "";
      num1 = num2 = 0;
      op = '\0';
      operatorSet = false;
      resultShown = false;
      lcd.clear();
      return;
    }

    // Tampilkan input real-time di baris pertama
    lcd.setCursor(0, 0);
    lcd.print(input);
    lcd.print("                "); // Bersihkan sisa karakter
  }
}
