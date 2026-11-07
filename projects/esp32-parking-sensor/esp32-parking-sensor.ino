#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);

const int trigPin = 25;
const int echoPin = 34;
const int redLed = 18;
const int greenLed = 17;
const int blueLed = 16;
const int buttonPin = 4;

const int NUM_READINGS = 5;
float readings[NUM_READINGS];
int readingIndex = 0;

int lastButton = 1;
bool isOn = false;

float readDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH, 30000);
  return duration * 0.034 / 2;
}

float averageDistance() {
  float sum = 0;
  int validCount = 0;
  for (int i = 0; i < NUM_READINGS; i++) {
    if (readings[i] > 0) {
      sum += readings[i];
      validCount++;
    }
  }
  if (validCount == 0) return 0;
  return sum / validCount;
}

void setLeds(float distance) {
  bool valid = distance > 0;
  digitalWrite(blueLed, valid && distance < 30);
  digitalWrite(greenLed, valid && distance < 15);
  digitalWrite(redLed, valid && distance < 5);
}

void displayDistance(float distance) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Distance:");
  display.setTextSize(2);
  display.setCursor(0, 20);
  if (distance > 0) {
    display.print(distance);
    display.print(" cm");
  } else {
    display.print("--");
  }
  display.display();
}

void turnOff() {
  setLeds(0);
  display.clearDisplay();
  display.display();
}

void handleButton() {
  int currentButton = digitalRead(buttonPin);
  if (currentButton == 0 && lastButton == 1) isOn = !isOn;
  lastButton = currentButton;
}

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextColor(SSD1306_WHITE);
  turnOff();
}

void loop() {
  handleButton();
  if (isOn) {
    readings[readingIndex] = readDistance();
    readingIndex = (readingIndex + 1) % NUM_READINGS;
    float distance = averageDistance();
    Serial.print("Distance: ");
    Serial.println(distance);
    setLeds(distance);
    displayDistance(distance);
  } else {
    turnOff();
  }
  delay(50);
}
