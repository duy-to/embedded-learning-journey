#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);

const int colorButtonPin  = A2;
const int screenButtonPin = A1;
const int trigPin = 7;
const int echoPin = 6;
int ledPins[3] = { 9, 10, 11 };

const int presenceLimit = 100;
const int NUM_READINGS  = 5;
float readings[NUM_READINGS];

int lastColorButton  = 1;
int lastScreenButton = 1;
int currentLed = 0;
bool isOn = true;

void ledState(int state) {
  if (state != 0 && state != 1) return;
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPins[i], state);
  }
}

float readDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long t = pulseIn(echoPin, HIGH, 30000);
  return (t * 0.034) / 2;
}

float averageDistance() {
  float results = 0;
  for (int i = 0; i < NUM_READINGS; i++) {
    readings[i] = readDistance();
    delay(30);
  }
  for (int i = 0; i < NUM_READINGS; i++) {
    results += readings[i];
  }
  return results / NUM_READINGS;
}

void displayOLED(float d) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Average Distance:");
  display.setTextSize(2);
  display.setCursor(0, 20);
  display.print(d);
  display.print(" cm");
  display.display();
}

void screenOff() {
  display.clearDisplay();
  display.display();
}

void handleColorButton() {
  int currentButton = digitalRead(colorButtonPin);
  if (currentButton == 0 && lastColorButton == 1) {
    ledState(0);
    digitalWrite(ledPins[currentLed], HIGH);
    currentLed++;
    if (currentLed > 2) currentLed = 0;
  }
  lastColorButton = currentButton;
}

void handleScreenButton() {
  int currentButton = digitalRead(screenButtonPin);
  if (currentButton == 0 && lastScreenButton == 1) isOn = !isOn;
  lastScreenButton = currentButton;
}

void setup() {
  Serial.begin(115200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextColor(SSD1306_WHITE);
  screenOff();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(colorButtonPin, INPUT_PULLUP);
  pinMode(screenButtonPin, INPUT_PULLUP);
}

void loop() {
  handleColorButton();
  handleScreenButton();
  if (isOn) {
    float d = averageDistance();
    if (d > 0 && d <= presenceLimit) {
      displayOLED(d);
    } else {
      screenOff();
    }
  } else {
    screenOff();
  }
  delay(20);
}
