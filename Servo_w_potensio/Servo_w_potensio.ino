#include <Servo.h>

Servo servo;
int angle = 10;

float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


void setup() {
  servo.attach(8);
  servo.write(angle);
  Serial.begin(9600);
}


void loop()
{
  // scan from 0 to 180 degrees

  int analogValue1 = analogRead(A0);
  angle = floatMap(analogValue1, 0, 1023, 0, 180);

  Serial.print("Analog 1: ");
  Serial.print(analogValue1);
  Serial.print(", Angle: ");
  Serial.println(angle);

  servo.write(angle);
}
