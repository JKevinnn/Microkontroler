*
   Created by ArduinoGetStarted.com

   This example code is in the public domain

   Tutorial page: https://arduinogetstarted.com/tutorials/arduino-potentiometer
*/

float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin A0:
  int analogValue1 = analogRead(A0);
  int analogValue2 = analogRead(A1);
  // Rescale to potentiometer's voltage (from 0V to 5V):
  float voltage1 = floatMap(analogValue1, 0, 1023, 0, 5);
  float voltage2 = floatMap(analogValue2, 0, 1023, 0, 5);

  // print out the value you read:
  Serial.print("Analog 1: ");
  Serial.print(analogValue1);
  Serial.print(", Voltage: ");
  Serial.print(voltage1);
  Serial.print("\tAnalog 2: ");
  Serial.print(analogValue2);
  Serial.print(", Voltage: ");
  Serial.println(voltage2);
  delay(1000);
}
