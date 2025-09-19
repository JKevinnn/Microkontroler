#include <LiquidCrystal.h>
#define tombol 7
bool baca = LOW;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int onop = 1;

void setup()
{
  pinMode(tombol, INPUT);
  lcd.begin(16, 2);

}

void loop()
{
  while (onop == 1) {
    baca = digitalRead(tombol);
    if (baca == HIGH)  {
      while (baca == HIGH) {
        lcd.clear();                 // clear display
        lcd.setCursor(4, 0);         // move cursor to   (0, 0)
        lcd.print("Hai Kamu");        // print message at (0, 0)
        lcd.setCursor(2, 1);         // move cursor to   (2, 1)
        lcd.print("KAMU JAWA");     // print message at (2, 1)
        delay(2000);                 // display the above for two seconds

        lcd.clear();                  // clear display
        lcd.setCursor(3, 0);          // move cursor to   (3, 0)
        lcd.print("GA ADA YANG");        // print message at (3, 0)
        lcd.setCursor(0, 1);          // move cursor to   (0, 1)
        lcd.print("MAU SAMA KAMU"); // print message at (0, 1)
        //delay(2000);                  // display the above for two seconds
        baca = digitalRead(tombol);
      }
      onop = 2;
    }
  }


   while (onop == 2) {
    baca = digitalRead(tombol);
    if (baca == HIGH)  {
      while (baca == HIGH) {
        lcd.clear();                 // clear display
        lcd.setCursor(0, 0);         // move cursor to   (0, 0)
        lcd.print("Engga bang");        // print message at (0, 0)
        lcd.setCursor(0, 1);         // move cursor to   (2, 1)
        lcd.print("Bercanda Bang");     // print message at (2, 1)
        delay(2000);                 // display the above for two seconds

        lcd.clear();                  // clear display
        lcd.setCursor(0, 0);          // move cursor to   (3, 0)
        lcd.print("Orang Jawa");        // print message at (3, 0)
        lcd.setCursor(0, 1);          // move cursor to   (0, 1)
        lcd.print("Keren kok hehe:D"); // print message at (0, 1)
        //delay(2000);                  // display the above for two seconds
        baca = digitalRead(tombol);

      }
      onop = 1;
    }
  }
}
