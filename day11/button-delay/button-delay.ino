const int buttonPin = 4;
const int ledPin = 18;
const int blinkDelay = 200;
const int pauseDelay = 500;

int lastButtonState = HIGH;
bool isBlinking = true;

bool isButtonPressed() {
  bool pressed = false;
  int buttonState = digitalRead(buttonPin);
  if (buttonState == LOW && lastButtonState == HIGH) {
    pressed = true;
  }
  lastButtonState = buttonState;
  delay(50);
  return pressed;
}

void doubleBlink() {
  for (int i = 0; i < 2; i++) {
    digitalWrite(ledPin, HIGH);
    delay(blinkDelay);
    digitalWrite(ledPin, LOW);
    delay(blinkDelay);
  }
  delay(pauseDelay);
}

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  if (isButtonPressed()) {
    isBlinking = !isBlinking;
  }
  if (isBlinking) {
    doubleBlink();
  }
}
