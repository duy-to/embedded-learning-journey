// Side project (Day 7) - Ultrasonic distance bar with an ON/OFF button
// Button (A5) toggles the system on and off (edge detection + 20 ms debounce).
// When on, LEDs show how close an object is:
//   closer than 30 cm -> blue, closer than 15 cm -> blue + green, closer than 5 cm -> all three.
// Wiring: TRIG pin 7, ECHO pin 6, red/green/blue LEDs on 9/10/11, button between A5 and GND.

int trigPin = 7;
int echoPin = 6;
int nearDistance = 20;

int LedStage = 0;
int redLed = 9;
int greenLed = 10;
int blueLed = 11;
int buttonStage = A5;
int lastButton = 1;

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(buttonStage, INPUT_PULLUP);
}
bool isOn = false;
void loop() {
  int currentButton = digitalRead(buttonStage);
  if (currentButton == 0 && lastButton == 1) { isOn = !isOn; }
  lastButton = currentButton;
  if (isOn == true) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    long duration = pulseIn(echoPin, HIGH, 30000);
    float distance = duration * 0.034 / 2;

    Serial.print("Distance: ");
    Serial.println(distance);

    if (duration > 0 && distance < 30) {
      digitalWrite(blueLed, HIGH);
      digitalWrite(greenLed, LOW);
      digitalWrite(redLed, LOW);
      if (distance < 15 && distance > 0) {
        digitalWrite(greenLed, HIGH);
        digitalWrite(redLed, LOW);
        if (distance < 5 && distance > 0) { digitalWrite(redLed, HIGH); }
      }
    } else {
      digitalWrite(blueLed, LOW);
      digitalWrite(redLed, LOW);
      digitalWrite(greenLed, LOW);
    }
  } else {
    digitalWrite(trigPin, LOW);
    digitalWrite(blueLed, LOW);
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, LOW);
  }

  delay(20);
}
