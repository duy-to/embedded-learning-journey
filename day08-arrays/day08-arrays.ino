const int buttonPin = A5;
int ledPins[3] = { 9, 10, 11 };
int ledMode = 10;
int dt = 150;
int lastButton = 1;
int currentLed = 0;

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i <= 2; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT_PULLUP);
}

void ledState(int state) {
  if (state != 0 && state != 1) {
    return;
  }
  for (int i = 0; i <= 2; i++) {
    digitalWrite(ledPins[i], state);
  }
}

void ledSeries(int time) {
  if (time < 0) return;
  for (int i = 0; i <= 2; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(time);
    digitalWrite(ledPins[i], LOW);
    delay(time);
  }
}

void ledSeriesReverse(int time) {
  if (time < 0) return;
  for (int i = 2; i >= 0; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(time);
    digitalWrite(ledPins[i], LOW);
    delay(time);
  }
}

void buttonStage(int time) {
  int currentButton = digitalRead(buttonPin);
  if (currentButton == 0 && lastButton == 1) {
    ledState(0);
    digitalWrite(ledPins[currentLed], HIGH);
    delay(time);
    currentLed++;
  }
  if (currentLed > 2) { currentLed = 0; }
  lastButton = currentButton;
  delay(20);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonStage(dt);
}
