const int ledPin = 18;
const int minBrightness = 0;
const int maxBrightness = 255;
unsigned long now = 0;
unsigned long lastLevelChange = 0;
const unsigned long stepInterval = 50;
const int brightnessStep = 5;
int brightness = 0;
bool goingUp = true;
void setup() {
  Serial.begin(115200);
}

void loop() {
  now = millis();
  if (now - lastLevelChange >= stepInterval) {
    lastLevelChange = now;
    analogWrite(ledPin, brightness);
    Serial.println(brightness);
    if (goingUp) {
      brightness += brightnessStep;
      if (brightness > maxBrightness) {
        goingUp = !goingUp;
        brightness = maxBrightness - brightnessStep;
      }
    } else {
      brightness -= brightnessStep;
      if (brightness < 0) {
        goingUp = !goingUp;
        brightness = minBrightness + brightnessStep;
        ;
      }
    }
  }
}
