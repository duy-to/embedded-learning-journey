const int buttonPin = 4;
const int redPin = 18;
const int yellowPin = 16;
const int greenPin = 17;

const int ledPins[] = { redPin, yellowPin, greenPin };
const int LED_COUNT = 3;

int lastState = 1;
int currentLed = 0;

bool buttonPressed() {
  bool pressed = false;
  int currentState = digitalRead(buttonPin);
  if (currentState != lastState) { delay(50); }
  if (lastState == 1 && currentState == 0) {
    pressed = true;
  }
  lastState = currentState;
  return pressed;
}

void changeColor() {
  digitalWrite(ledPins[currentLed], LOW);
  currentLed++;
  if (currentLed == LED_COUNT) { currentLed = 0; }
  digitalWrite(ledPins[currentLed], HIGH);
}

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  for (int i = 0; i < LED_COUNT; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  digitalWrite(ledPins[currentLed], HIGH);
  Serial.begin(115200);
}

void loop() {
  if (buttonPressed()) { changeColor(); }
}
