

#define m1 22
#define k1 24
#define h1 26

#define m2 28
#define k2 30
#define h2 32

#define m3 34
#define k3 36
#define h3 38

int waktu1 = 3000;
int waktu2 = 500;
int waktu3 = 8000;
int waktu4 = 4000;


void jalur1 () {
  hijau1 ();
  delay(waktu1);
  kuning1 ();
  delay(waktu2);
  merah1 ();
  delay(waktu3);
  kuning1 ();
  delay(waktu2);
}

void jalur2 () {
  merah2 ();
  delay(waktu3);
  kuning2 ();
  delay(waktu2);
  hijau2 ();
  delay(waktu1);
  kuning1 ();
  delay(waktu2);
}

void jalur3 () {
  merah3 ();
  delay(waktu1);
  kuning3 ();
  delay(waktu2);
  hijau3();
  delay(waktu1);
  kuning3 ();
  delay(waktu2);
  merah3 ();
  delay(waktu1);
}
void merah1 () {
  digitalWrite (m1, HIGH);
  digitalWrite (k1, LOW);
  digitalWrite (h1, LOW);
}

void merah2 () {
  digitalWrite (m2, HIGH);
  digitalWrite (k2, LOW);
  digitalWrite (h2, LOW);
}

void merah3 () {
  digitalWrite (m3, HIGH);
  digitalWrite (k3, LOW);
  digitalWrite (h3, LOW);
}

void hijau1 () {
  digitalWrite (m1, LOW);
  digitalWrite (k1, LOW);
  digitalWrite (h1, HIGH);
}

void hijau2 () {
  digitalWrite (m2, LOW);
  digitalWrite (k2, LOW);
  digitalWrite (h2, HIGH);
}

void hijau3 () {
  digitalWrite (m3, LOW);
  digitalWrite (k3, LOW);
  digitalWrite (h3, HIGH);
}

void kuning1 () {
  digitalWrite (m1, LOW);
  digitalWrite (k1, HIGH);
  digitalWrite (h1, LOW);
}

void kuning2 () {
  digitalWrite (m2, LOW);
  digitalWrite (k2, HIGH);
  digitalWrite (h2, LOW);
}

void kuning3 () {
  digitalWrite (m3, LOW);
  digitalWrite (k3, HIGH);
  digitalWrite (h3, LOW);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(m1, OUTPUT);
  pinMode(k1, OUTPUT);
  pinMode(h1, OUTPUT);

  pinMode(m2, OUTPUT);
  pinMode(k2, OUTPUT);
  pinMode(h2, OUTPUT);

  pinMode(m3, OUTPUT);
  pinMode(k3, OUTPUT);
  pinMode(h3, OUTPUT);

  digitalWrite (m1, LOW);
  digitalWrite (k1, LOW);
  digitalWrite (h1, LOW);

  digitalWrite (m2, LOW);
  digitalWrite (k2, LOW);
  digitalWrite (h2, LOW);

  digitalWrite (m3, LOW);
  digitalWrite (k3, LOW);
  digitalWrite (h3, LOW);
}

void loop() {
  jalur1 ();
  jalur2 ();
  jalur3 ();
}
