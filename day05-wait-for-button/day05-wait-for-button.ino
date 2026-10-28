// Day 5 (Bai 10) - Wait for a button press, then blink the LED exactly 5 times
// Button on A5 with INPUT_PULLUP (released = 1, pressed = 0), LED on pin 13.
// The empty while loop "polls" the button until it is pressed.

int redLed = 13;
int buttonRead = A5;
int i = 1;
int dt = 200;

void setup() {
  Serial.begin(115200);
  Serial.println("Bam nut de bat dau ^-^");
  pinMode(redLed, OUTPUT);
  pinMode(buttonRead, INPUT_PULLUP);

  while (digitalRead(buttonRead) == 1) {}   // wait here until pressed

  while (i <= 5) {
    i++;
    digitalWrite(redLed, HIGH);
    delay(dt);
    digitalWrite(redLed, LOW);
    delay(dt);
  }
}

void loop() {
}
