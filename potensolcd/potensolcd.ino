// include the library code:
#include <LiquidCrystal.h>
float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int val1;
float voltage1;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  val1 = analogRead(A0);
  float data = floatMap(val1, 0, 1023, 0, 100);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Value  : ");
  lcd.print(val1);
  lcd.setCursor(0,1);
  lcd.print("Data  : ");
  lcd.print(data);
  delay(1000);
}
