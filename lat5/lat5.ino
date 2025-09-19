#define ledPin 2  // LED warna Merah
#define inPin 5   // PushButton warna Kuning

int onop = 1;
bool baca = LOW;

void setup() {

  pinMode(ledPin, OUTPUT);
  pinMode(inPin, INPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  while (onop == 1) {
    baca = digitalRead(inPin);
    if (baca == HIGH) {
      while (baca == HIGH) {
        baca = digitalRead(inPin);
      }
      digitalWrite(ledPin, HIGH);
      onop = 2;
    }
  }

  while (onop == 2) {
    baca = digitalRead(inPin);
    if (baca == HIGH) {
      while (baca == HIGH) {
        baca = digitalRead(inPin);
      }
      digitalWrite(ledPin, LOW);
      onop = 1;
    }
  }
}