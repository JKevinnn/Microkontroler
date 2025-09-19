const int touchSensorDigitalPin = 2; // Connect the sensor's digital pin to Arduino pin 2
const int touchSensorAnalogPin = A0; // Connect the sensor's analog pin to Arduino A0
const int led = 3;
void setup() {
  Serial.begin(9600); // Start serial communication
  pinMode(touchSensorDigitalPin, INPUT); // Set the sensor's digital pin as input
  pinMode(led, OUTPUT);
}
void loop() {
  int touchValue = digitalRead(touchSensorDigitalPin); // Read the digital output value
  if (touchValue == HIGH) { // If the sensor is touched (assuming HIGH state for touch)
    int touchAnalogValue = analogRead(touchSensorAnalogPin); // Read the analog value
    Serial.print("Metal touch detected! Analog value: "); // Print message to Serial Monitor
    Serial.println(touchAnalogValue); // Print the analog value
    digitalWrite(led, HIGH);
    delay(100); // Delay to avoid multiple rapid detections
  }
  else {
    digitalWrite(led, LOW);
  }
}
