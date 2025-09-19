/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-led-fade
 */

#define LED_PIN 9  // the Arduino PWM pin connected to the LED

int brightness = 0;  // how bright the LED is
int fadeAmount = 5;  // how many points to fade the LED by

float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(LED_PIN, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  int analogValue = analogRead(A0);
  // Rescale to potentiometer's voltage (from 0V to 5V):
  float brightness = floatMap(analogValue, 0, 1023, 0, 10);
  // set the brightness of pin 9:
  analogWrite(LED_PIN, brightness);

  // change the brightness for next time through the loop:
  // brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  /*if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }*/
  // wait for 30 milliseconds to see the dimming effect
  //delay(30);
}
