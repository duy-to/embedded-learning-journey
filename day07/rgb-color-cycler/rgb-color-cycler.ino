// Day 7 (review) - Each button press switches to the next colour: red -> green -> blue -> red
// Topics: edge detection (act only when the button goes from 1 to 0) and debounce (delay 20 ms)
// Holding the button changes the colour only once; the colour stays on after release.
// Wiring: same as day06-rgb-led-sequence (LEDs on 9/10/11, button on A5).

int LedStage = 0;
int redLed = 9;
int greenLed = 10;
int blueLed = 11;
int buttonStage = A5;
int lastButton = 1;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(buttonStage, INPUT_PULLUP);
}

void loop() {
  int currentButton = digitalRead(buttonStage);
  if (currentButton == 0 && lastButton == 1 && LedStage == 0) {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(blueLed, LOW);
    LedStage++;
  } else if (currentButton == 0 && lastButton == 1 && LedStage == 1) {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    digitalWrite(blueLed, LOW);
    LedStage++;
  } else if (currentButton == 0 && lastButton == 1 && LedStage == 2) {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, LOW);
    digitalWrite(blueLed, HIGH);
    LedStage = 0;
  }
  lastButton = currentButton;   // runs every loop, outside the if
  delay(20);                    // debounce
}
