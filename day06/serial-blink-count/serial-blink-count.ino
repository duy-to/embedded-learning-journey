// Day 6 (warm-up) - Type a number in the Serial Monitor, the LED blinks that many times
// Topics: Serial.available, Serial.parseFloat, round(), clearing the input buffer
// Typing 3.7 blinks 4 times because the value is read as float then rounded.

int dt = 200;
float preNumber;
int numBlinks;
int ledPin = 13;
String msg = "How many times you want to blink: ";

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  Serial.println(msg);
  while (Serial.available() == 0) {}   // wait for input
  preNumber = Serial.parseFloat();
  numBlinks = round(preNumber);
  for (int start = 1; start <= numBlinks; start++) {
    digitalWrite(ledPin, HIGH);
    delay(dt);
    digitalWrite(ledPin, LOW);
    delay(dt);
  }
  while (Serial.available() >= 1) {    // throw away leftover characters (e.g. newline)
    Serial.read();
  }
}
