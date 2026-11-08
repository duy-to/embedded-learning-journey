// Day 5 (Q4) - Sum 1 + 2 + ... + 100 = 5050
// Lesson learned: reset the global total (r = 0) at the start of every loop(),
// otherwise it keeps growing each time loop() runs again.

int i;
int r = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  r = 0;
  for (i = 1; i <= 100; i++) {
    r += i;
    Serial.print(" ");
    delay(50);
  }
  Serial.println(r);
}
