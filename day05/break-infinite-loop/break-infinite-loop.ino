// Day 5 (Bai 8) - An infinite while loop (x never changes) rescued by break
// Prints 1..5 then leaves the loop. Remove the if/break to see it run forever.

int x = 0;
int i = 0;

void setup() {
  Serial.begin(115200);
  while (x < 5) {
    i++;
    Serial.println(i);
    if (i == 5) {
      break;
    }
  }
}

void loop() {
}
