// Day 5 (Bai 6) - while loop: keep doubling r from 1 until it reaches 1000
// Result: r = 1024 after i = 10 doublings. Runs once, so it lives in setup().

int i = 0;
int r = 1;

void setup() {
  Serial.begin(115200);
  while (r < 1000) {
    r *= 2;
    i++;
  }
  Serial.println(r);
  Serial.println(i);
}

void loop() {
}
