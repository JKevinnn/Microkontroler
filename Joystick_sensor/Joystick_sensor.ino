/*
   Created by ArduinoGetStarted.com

   This example code is in the public domain

   Tutorial page: https://arduinogetstarted.com/tutorials/arduino-joystick
*/

#define pinx  A0 // Arduino pin connected to VRX pin
#define piny  A1 // Arduino pin connected to VRY pin
#define r3 2
#define led1 3 // merah
#define led2 4 // kuning
#define led3 5 // hijau

int xValue = 0; // To store value of the X axis
int yValue = 0; // To store value of the Y axis
int r3value = 0;

void setup() {
  Serial.begin(9600) ;
  pinMode(pinx, INPUT);
  pinMode(piny, INPUT);
  pinMode(r3, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  // read analog X and Y analog values
  xValue = analogRead(pinx);
  yValue = analogRead(piny);
  r3value = digitalRead(r3);

  if ((xValue >= 0 && xValue <= 470) | (yValue >= 0 && yValue <= 470)) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  }
  if ((xValue >= 600 && xValue <= 1100) | (yValue >= 600 && yValue <= 1100)) {
    digitalWrite(led2, HIGH);
    digitalWrite(led1, LOW);
  }
  if (r3value == 0) {
    digitalWrite(led3, HIGH);
  }
  /*else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    }*/

  // print data to Serial Monitor on Arduino IDE
  Serial.print("x = ");
  Serial.print(xValue);
  Serial.print(", y = ");
  Serial.print(yValue);
  Serial.print(", r3 = ");
  Serial.println(r3value);
}
