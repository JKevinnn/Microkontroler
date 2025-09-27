#include <LiquidCrystal.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;
char hexaKeys[ROWS][COLS] = {
  {'D', 'C', 'B', 'A'},
  {'#', '9', '6', '3'},
  {'0', '8', '5', '2'},
  {'*', '7', '4', '1'}
};

byte rowPins[ROWS] = {37, 35, 33, 31};
byte colPins[COLS] = {45, 43, 41, 39};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

char pw[7] = "000000";
char inputPw[7] = "";
int ipw = 0;
int kons = 1;

long saldo = 0; // Saldo awal
String inputNominal = "";
bool inputMode = false;
int transaksiMode = 0; // 1 = tarik, 2 = setor

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  char input = customKeypad.getKey();

  if (kons == 1) {
    lcd.setCursor(0, 0);
    lcd.print("Welcome diBank");
    lcd.setCursor(0, 1);
    lcd.print("PW : ");
    kons = 2;
  }

  if (kons == 2 && input) {
    if (input == '#' && ipw > 0) {
      ipw--;
      inputPw[ipw] = '\0';
      lcd.setCursor(5 + ipw, 1);
      lcd.print(" ");
    } else if (ipw < 6 && input != '#' && input != '*') {
      inputPw[ipw] = input;
      lcd.setCursor(5 + ipw, 1);
      lcd.print("*");
      ipw++;
    }

    if (ipw == 6) {
      inputPw[6] = '\0';
      if (strcmp(inputPw, pw) == 0) {
        kons = 3;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Login Berhasil");
        delay(1000);
        showMenu();
      } else {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Salah! Coba lagi");
        delay(2000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Welcome diBank");
        lcd.setCursor(0, 1);
        lcd.print("PW : ");
        ipw = 0;
        memset(inputPw, 0, sizeof(inputPw));
      }
    }
  }

  if (kons == 3 && input) {
    if (!inputMode) {
      switch (input) {
        case '1':
          transaksiMode = 1;
          inputMode = true;
          inputNominal = "";
          lcd.clear();
          lcd.print("Nominal Tarik:");
          lcd.setCursor(0, 1);
          break;
        case '2':
          transaksiMode = 2;
          inputMode = true;
          inputNominal = "";
          lcd.clear();
          lcd.print("Nominal Setor:");
          lcd.setCursor(0, 1);
          break;
        case '3':
          lcd.clear();
          lcd.print("Saldo: ");
          lcd.setCursor(0, 1);
          lcd.print(saldo);
          delay(2000);
          showMenu();
          break;
        case '4':
          kons = 1;
          ipw = 0;
          memset(inputPw, 0, sizeof(inputPw));
          lcd.clear();
          lcd.print("Logout...");
          delay(1000);
          lcd.clear();
          break;
      }
    } else {
      if (input == '#') {
        if (inputNominal.length() > 0) {
          inputNominal.remove(inputNominal.length() - 1);
          lcd.setCursor(0, 1);
          lcd.print("                ");
          lcd.setCursor(0, 1);
          lcd.print(inputNominal);
        }
      } else if (input == '*') {
        long nominal = atol(inputNominal.c_str());
        if (transaksiMode == 1) {
          if (saldo >= nominal) {
            saldo -= nominal;
            lcd.clear();
            lcd.print("Tarik: ");
            lcd.print(nominal);
          } else {
            lcd.clear();
            lcd.print("Saldo kurang");
          }
        } else if (transaksiMode == 2) {
          saldo += nominal;
          lcd.clear();
          lcd.print("Setor: ");
          lcd.print(nominal);
        }
        delay(2000);
        inputMode = false;
        transaksiMode = 0;
        showMenu();
      } else if (isDigit(input)) {
        if (inputNominal.length() < 10) {
          inputNominal += input;
          lcd.setCursor(0, 1);
          lcd.print(inputNominal);
        }
      }
    }
  }
}

void showMenu() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("1.Tarik 2.Setor");
  lcd.setCursor(0, 1);
  lcd.print("3.Cek   4.LogOut");
}
