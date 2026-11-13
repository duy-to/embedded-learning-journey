const int potPin = 34;
const int ledPin = 18;
unsigned long lastReadTime = 0;
const unsigned long readInterval = 100;

void readKnob(int pin, int* rawPtr, int* brightnessPtr) {
  int rawValue = analogRead(pin);
  *rawPtr = rawValue;
  int brightness = rawValue >> 4;
  *brightnessPtr = brightness;
}
void setup() {
  Serial.begin(115200);
  pinMode(ledPin,OUTPUT);
}
void loop() {
  unsigned long now = millis();
  if (now - lastReadTime >= readInterval) {
    lastReadTime = now;
    int rawValue;
    int brightness;
    readKnob(potPin, &rawValue, &brightness);
    analogWrite(ledPin,brightness);
    Serial.println(rawValue);
    Serial.println(brightness);
  }
}
