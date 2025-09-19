int i = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(5, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (i; i<2; i++){tone (5, HIGH);
  delay (500);
  noTone (5);
  delay (1000);
  }
  /*
  tone (5, HIGH);
  delay (500);
  noTone (5);
  delay (1000);
  digitalWrite(5, HIGH);
  delay (100);
  digitalWrite(5, LOW);
  delay (500);*/
}
