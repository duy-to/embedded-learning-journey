// Day 5 (Q3) - Print even numbers 0..20 in two ways
// Way 1: step the loop by 2.  Way 2: step by 1 and keep numbers where i % 2 == 0.

int i;

void setup() {
  Serial.begin(115200);
}

void loop() {
  // Way 1: i = i + 2
  for (i = 0; i <= 20; i = i + 2) {
    Serial.print(" ");
    Serial.print(i);
    delay(500);
  }
  Serial.println();

  // Way 2: remainder operator %
  for (i = 0; i <= 20; i++) {
    if (i % 2 == 0) {
      Serial.print(" ");
      Serial.print(i);
      delay(500);
    }
  }
  Serial.println();
}
