#define ledPin    2 // LED  Merah
#define inPin     5 // PushButton  

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
    if (baca == HIGH)  {
      digitalWrite(ledPin, HIGH);
      while (baca == HIGH) {
        digitalWrite(ledPin, HIGH);
        baca = digitalRead(inPin);
      }
      onop = 2;
    }
  }


  while (onop == 2) {
    baca = digitalRead(inPin);
    if (baca == HIGH)  {
      digitalWrite(ledPin, LOW);
      while (baca == HIGH) {
        digitalWrite(ledPin, LOW);
        baca = digitalRead(inPin);
      }
      onop = 1;
    }
  }
}