// Day 2 - Three LEDs blink 5 / 10 / 15 times at different speeds.
// Rule of the exercise: no magic numbers inside loop() - every number is a named variable.
// Serial Monitor (115200 baud) shows which LED is blinking and the count.
// setup() also prints the parallel resistance of 220 and 100 ohm (68.75 ohm).
// Wiring: green LED pin 13, yellow LED pin 12, red LED pin 11 (each with 220 ohm to GND)

int fast = 100;
int slow = 500;
int rslow = 1000;
int greenLED = 13;
int yellowLED = 12;
int redLED = 11;
int start = 1;
int fastTimes = 5;
int slowTimes = 10;
int rslowTimes = 15;

void setup() {
  Serial.begin(115200);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  Serial.println("Hello, minh la Duy");
  Serial.println("Hom nay minh hoc bien");

  // Equivalent resistance of two resistors in parallel (printed once)
  float R1 = 220;
  float R2 = 100;
  float result = (R1 * R2) / (R1 + R2);
  Serial.print(result);
  Serial.println(" Ohms");
}

void loop() {
  for (int times = start; times <= fastTimes; times++) {
    Serial.print("Green: ");
    Serial.print(times);
    Serial.println(" times");
    digitalWrite(greenLED, HIGH);
    delay(fast);
    digitalWrite(greenLED, LOW);
    delay(fast);
  }
  for (int times = start; times <= slowTimes; times++) {
    Serial.print("Yellow: ");
    Serial.print(times);
    Serial.println(" times");
    digitalWrite(yellowLED, HIGH);
    delay(slow);
    digitalWrite(yellowLED, LOW);
    delay(slow);
  }
  for (int times = start; times <= rslowTimes; times++) {
    Serial.print("Red: ");
    Serial.print(times);
    Serial.println(" times");
    digitalWrite(redLED, HIGH);
    delay(rslow);
    digitalWrite(redLED, LOW);
    delay(rslow);
  }
}
