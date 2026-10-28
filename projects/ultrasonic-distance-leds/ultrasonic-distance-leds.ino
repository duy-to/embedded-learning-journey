// Side project (Day 5) - HC-SR04 ultrasonic sensor with a red/green LED
// Object closer than 10 cm -> red LED on, otherwise green LED on.
// Wiring: TRIG pin 7, ECHO pin 11, green LED pin 10, red LED pin 9 (each with 220R to GND),
//         sensor VCC to 5V and GND to GND.
// distance (cm) = echo time (us) * 0.034 cm/us / 2   (sound goes there and back)

int echoPin = 11;
int trigPin = 7;
int greenPin = 10;
int redPin = 9;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // 10 us pulse on TRIG starts one measurement
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long t = pulseIn(echoPin, HIGH);
  float d = (t * 0.034) / 2;
  Serial.println(d);
  delay(100);

  if (d > 0 && d <= 10) {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
  } else {
    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
  }
}
