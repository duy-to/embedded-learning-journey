// Day 4 (extra) - Push button controls an LED
// Button uses INPUT_PULLUP: released = HIGH (1), pressed = LOW (0)
// Wiring: button between pin 9 and GND (use two diagonal legs of the 4-leg button)
//         LED on pin 10 with 220 ohm resistor to GND
// Behaviour: LED is on only while the button is held down.

const int buttonPin = 9;
const int ledPin = 10;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
