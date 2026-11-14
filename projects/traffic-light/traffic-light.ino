// Traffic light with pedestrian button and 7-segment countdown (ESP32)
//
// States and timing:
//   GREEN  : 3-10 s (set by pot, read once when green starts; first cycle 8 s)
//   YELLOW : 3 s
//   RED    : 7 s
//   Order  : GREEN -> YELLOW -> RED -> GREEN ...
//
// Pedestrian button:
//   Press during GREEN -> green ends 1 s after the press
//   (if less than 1 s is left, green just ends normally)
//   Press during YELLOW or RED -> ignored
//   Debounce 50 ms with millis(), count on the press edge only
//
// Pins:
//   LEDs   : RED 18, GREEN 17, YELLOW 16 (220 ohm each)
//   Button : GPIO4 -> GND, external 10k pull-up to 3V3 (pinMode INPUT, pressed = LOW)
//   Pot    : wiper -> GPIO34 (ADC 0-4095)
//
// 7-segment: 3461AS, common cathode, digit 1 only (pin 12 -> GND), HIGH = segment on
//   a=13  b=14  c=25  d=26  e=27  f=32  g=33  (220 ohm each, ~7.3 mA per segment)
//   Shows whole seconds left in the current state, e.g. RED: 6, 5, 4, 3, 2, 1, 0
//   (one digit only, so values above 9 are shown as 9)

const int ledPins[] = { 17, 16, 18 };
const int numberOfLedPins = sizeof(ledPins) / sizeof(ledPins[0]);
const int segmentPins[] = { 13, 14, 25, 26, 27, 32, 33 };
const int potPin = 34;
const int buttonPin = 4;
unsigned long now = 0;
unsigned long lastCheck = 0;
unsigned long lastChangeTime = 0;
unsigned long debounceInterval = 50;
unsigned long ledIntervals[] = { 8000, 3000, 7000 };  //Green - Yellow - Red
int ledNumber = 0;
bool stableState = 1;
bool lastReading = false;
const byte digitPatterns[] = { 0b0111111,
                               0b0000110,
                               0b1011011,
                               0b1001111,
                               0b1100110,
                               0b1101101,
                               0b1111101,
                               0b0000111,
                               0b1111111,
                               0b1101111 };
void setup() {
  Serial.begin(115200);
  for (int i = 0; i < numberOfLedPins; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  pinMode(potPin, INPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(ledPins[0], HIGH);
}

void showDigit(int digit) {
  byte pattern = digitPatterns[digit];
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], bitRead(pattern, i));
  }
}

void ledLight() {
  ledNumber++;
  if (ledNumber > 2) {
    ledNumber = 0;
    readPot();
  }
  for (int i = 0; i < numberOfLedPins; i++) {
    if (i == ledNumber) {
      digitalWrite(ledPins[ledNumber], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }
}

void readPot() {
  unsigned long rawValue = analogRead(potPin);
  ledIntervals[0] = ((rawValue * 7000) / 4095) + 3000;
}

bool buttonState() {
  bool reading = digitalRead(buttonPin);
  bool pressed = false;
  if (reading != lastReading) {
    lastChangeTime = now;
    lastReading = reading;
  }
  if (now - lastChangeTime >= debounceInterval) {
    if (reading == 0 && stableState == 1) {
      pressed = true;
    }
    stableState = reading;
  }
  return pressed;
}

void ifPressButton(bool pressedButton) {
  if (ledNumber == 0 && pressedButton) {
    unsigned long elapsed = now - lastCheck;
    unsigned long timeLeft = ledIntervals[0] - elapsed;
    if (timeLeft > 1000) {
      ledIntervals[0] = elapsed + 1000;
    }
  }
}

void loop() {
  now = millis();
  if (now - lastCheck >= ledIntervals[ledNumber]) {
    lastCheck = now;
    ledLight();
  }
  ifPressButton(buttonState());
  int n = (ledIntervals[ledNumber] - (now - lastCheck)) / 1000;
  n = constrain(n, 0, 9);
  showDigit(n);
}
