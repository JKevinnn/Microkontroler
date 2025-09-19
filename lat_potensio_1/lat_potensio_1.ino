#include <TM1637Display.h>

#define CLK 10
#define DIO 11

TM1637Display display(CLK, DIO);

float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void setup() {
  Serial.begin(9600);
  display.setBrightness(7);
  display.clear();
}

void loop() {
  int analogValue = analogRead(A0);
  float voltage = floatMap(analogValue, 0, 1023, 0, 5);

  Serial.print("Analog: ");
  Serial.print(analogValue);
  Serial.print(", Voltage: ");
  Serial.println(voltage);

  // Konversi ke format x.xx volt
  int voltageInt = (int)(voltage * 100); // Contoh: 3.25V → 325

  // Tampilkan dengan titik desimal di posisi kedua (x.xx)
  display.showNumberDecEx(voltageInt, 0b01000000, true, 4); // titik di digit ke-2
  delay(200);
}
