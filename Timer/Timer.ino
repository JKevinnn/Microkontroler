#include <LiquidCrystal.h>
#include <Keypad.h>

#define inPin1 22  // Start
#define inPin2 24  // Pause
#define inPin3 26  // Reset
#define inPin4 28  // Clear

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int ROW_NUM = 4;
const int COLUMN_NUM = 4;

char keys[ROW_NUM][COLUMN_NUM] = {
  {'D', 'C', 'B', 'A'},
  {'#', '9', '6', '3'},
  {'0', '8', '5', '2'},
  {'*', '7', '4', '1'}
};

byte pin_rows[ROW_NUM] = {37, 35, 33, 31};
byte pin_column[COLUMN_NUM] = {45, 43, 41, 39};

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);

bool isRunning = false;
bool isPaused = false;
bool isInputMode = true;
bool isReset = false;

bool prevStartBtn = LOW;
bool prevPauseBtn = LOW;
bool prevResetBtn = LOW;
bool prevClearBtn = LOW;

unsigned long totalTime = 0;
unsigned long remainingTime = 0;
unsigned long lastUpdate = 0;

char inputBuffer[7];
int inputPos = 0;

void setup() {
  Serial.begin(9600);
  pinMode(inPin1, INPUT);
  pinMode(inPin2, INPUT);
  pinMode(inPin3, INPUT);
  pinMode(inPin4, INPUT);

  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Input Time:");
  lcd.setCursor(0, 1);
  lcd.print("HHMMSS");
  memset(inputBuffer, 0, sizeof(inputBuffer));
}

void start() {
  if (isInputMode) {
    lcd.clear();
    lcd.print("Input Time:");
    lcd.setCursor(0, 1);
    lcd.print("HHMMSS");
    return;
  }
  if (!isRunning && !isPaused && remainingTime > 0) {
    isRunning = true;
    isPaused = false;
    lastUpdate = millis();
  } else if (isPaused && remainingTime > 0) {
    isRunning = true;
    isPaused = false;
    lastUpdate = millis();
  }
}

void pause() {
  if (isRunning && !isPaused) {
    isPaused = true;
    isRunning = false;
    displayTime(remainingTime);
  }
}

void reset() {
  if (isRunning || isPaused) {
    isRunning = false;
    isPaused = false;
    remainingTime = totalTime;
    lcd.clear();
    isReset = true;
    lcd.print("Reset Time");
    delah(500);
    lcd.clear();
    displayTime(remainingTime);
  }
}

void clearInput() {
  if (!isRunning && !isPaused || isReset) {
    isInputMode = true;
    isRunning = false;
    isPaused = false;
    isReset = false;

    totalTime = 0;
    remainingTime = 0;
    inputPos = 0;
    memset(inputBuffer, 0, sizeof(inputBuffer));
    lcd.clear();
    lcd.print("Input Time:");
    lcd.setCursor(0, 1);
    lcd.print("HHMMSS");
  }
}

void displayTime(unsigned long ms) {
  unsigned long totalSeconds = ms / 1000;
  int hours = totalSeconds / 3600;
  int minutes = (totalSeconds % 3600) / 60;
  int seconds = totalSeconds % 60;

  lcd.setCursor(0, 1);
  if (hours < 10) lcd.print("0");
  lcd.print(hours);
  lcd.print(":");
  if (minutes < 10) lcd.print("0");
  lcd.print(minutes);
  lcd.print(":");
  if (seconds < 10) lcd.print("0");
  lcd.print(seconds);
  lcd.print("        ");
}

void loop() {
  bool startBtn = digitalRead(inPin1);
  bool pauseBtn = digitalRead(inPin2);
  bool resetBtn = digitalRead(inPin3);
  bool clearBtn = digitalRead(inPin4);

  if (isInputMode) {
    char key = keypad.getKey();
    if (key) {
      if (key >= '0' && key <= '9') {
        if (inputPos < 6) {
          inputBuffer[inputPos] = key;
          lcd.setCursor(inputPos, 1);
          lcd.print(key);
          inputPos++;
        }
      }
      if (inputPos == 6) {
        int hh = (inputBuffer[0] - '0') * 10 + (inputBuffer[1] - '0');
        int mm = (inputBuffer[2] - '0') * 10 + (inputBuffer[3] - '0');
        int ss = (inputBuffer[4] - '0') * 10 + (inputBuffer[5] - '0');

        if (mm > 59 || ss > 59) {
          lcd.clear();
          lcd.print("Input Time:");
          lcd.setCursor(0, 1);
          lcd.print("HHMMSS");
          inputPos = 0;
          memset(inputBuffer, 0, sizeof(inputBuffer));
        } else {
          totalTime = ((unsigned long)hh * 3600 + (unsigned long)mm * 60 + (unsigned long)ss) * 1000UL;
          remainingTime = totalTime;
          isInputMode = false;
          lcd.clear();
          displayTime(remainingTime);
        }
      }
    }
  }

  if (startBtn == HIGH && prevStartBtn == LOW) {
    start();
  }
  if (pauseBtn == HIGH && prevPauseBtn == LOW) {
    pause();
  }
  if (resetBtn == HIGH && prevResetBtn == LOW) {
    reset();
  }
  if (clearBtn == HIGH && prevClearBtn == LOW) {
    clearInput();
  }

  prevStartBtn = startBtn;
  prevPauseBtn = pauseBtn;
  prevResetBtn = resetBtn;
  prevClearBtn = clearBtn;

  if (isRunning) {
    unsigned long now = millis();

    if (now - lastUpdate >= 100) {
      lastUpdate = now;

      if (remainingTime >= 100) {
        remainingTime -= 1000;
        displayTime(remainingTime);
      } else {
        remainingTime = 0;
        isRunning = false;
        lcd.clear();
        lcd.setCursor(0, 1);
        lcd.print("Reset NOW");
      }
    }
  } else if (isPaused) {
    displayTime(remainingTime);
  }
}
