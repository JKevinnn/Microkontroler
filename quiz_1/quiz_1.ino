#define merah   2 // LED  Merah
#define kuning  3 // LED  kuning
#define hijau   4 // LED  hijau
#define tombol    8 // PushButton
#define A    9 // PushButton
#define B    10 // PushButton  

int onop = 1;
bool baca = LOW;

void setup() {

  pinMode(merah, OUTPUT);
  pinMode(kuning, OUTPUT);
  pinMode(hijau, OUTPUT);
  pinMode(tombol, INPUT);
  pinMode(A, INPUT);
  pinMode(B, INPUT);
  digitalWrite(merah, LOW);
  digitalWrite(kuning, LOW);
  digitalWrite(hijau, LOW);
}

void loop() {
  while (onop == 1) {
    baca = digitalRead(tombol);
    if (baca == HIGH)  {
      baca = digitalRead(tombol);
      while (onop == 1) {
        baca = digitalRead(tombol);
        while (baca == LOW) {
        delay (200);
          digitalWrite(merah, HIGH);
          delay(200);
          digitalWrite(merah, LOW);
          digitalWrite(kuning, HIGH);
          baca = digitalRead(tombol);
          if (baca == HIGH) {
            onop = 2;
            goto mati;
          }
          delay(200);
          if (baca == HIGH) {
            onop = 2;
            goto mati;
          }
          digitalWrite(kuning, LOW);
          digitalWrite(hijau, HIGH);
          baca = digitalRead(tombol);
          if (baca == HIGH) {
            onop = 2;
            goto mati;
          }
          delay(200);
          if (baca == HIGH) {
            onop = 2;
            goto mati;
          }
          digitalWrite(hijau, LOW);
          baca = digitalRead(tombol);
          if (baca == HIGH) {
            onop = 2;
            goto mati;
          }
        }
      }
    }
  }

mati :
  if (onop == 2) {
    baca = digitalRead(tombol);
    if (baca == HIGH)  {
      digitalWrite(merah, LOW);
      digitalWrite(kuning, LOW);
      digitalWrite(hijau, LOW);
      while (baca == HIGH) {
        digitalWrite(merah, LOW);
        digitalWrite(kuning, LOW);
        digitalWrite(hijau, LOW);
        baca = digitalRead(tombol);
      }
      onop = 1;
    }
  }
}
