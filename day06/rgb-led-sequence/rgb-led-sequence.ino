// Day 6 (hardware) - Red, green, blue LEDs, each with its own resistor
// Press the button (A5, INPUT_PULLUP) to run: red, green, blue for 1 s each, then all three.
// Wiring: pin 9 -> 330R -> red LED, pin 10 -> 220R -> green LED, pin 11 -> 180R -> blue LED,
//         all LEDs to a shared GND row. Button between A5 and GND (diagonal legs).
// Finding: brightness is not proportional to current; a shared 220R is fine for indicators.

int redPin = 9;
int greenPin = 10;
int buttonStage = A5;
int bluePin = 11;
int dt = 1000;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buttonStage, INPUT_PULLUP);
}

void loop() {
  while (digitalRead(buttonStage) == 1) {}   // wait for a press
  digitalWrite(redPin, HIGH);
  delay(dt);
  digitalWrite(redPin, LOW);
  delay(dt);
  digitalWrite(greenPin, HIGH);
  delay(dt);
  digitalWrite(greenPin, LOW);
  delay(dt);
  digitalWrite(bluePin, HIGH);
  delay(dt);
  digitalWrite(bluePin, LOW);
  delay(dt);
  digitalWrite(redPin, HIGH); digitalWrite(greenPin, HIGH); digitalWrite(bluePin, HIGH);
  delay(dt);
  digitalWrite(redPin, LOW); digitalWrite(greenPin, LOW); digitalWrite(bluePin, LOW);
}
