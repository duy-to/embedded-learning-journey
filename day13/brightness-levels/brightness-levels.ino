const int ledPin = 18;
const int brightnessLevels[] = { 0, 64, 128, 192, 255 };
unsigned long now = 0;
unsigned long lastLevelChange = 0;
const unsigned long levelInterval = 100;
int levelIndex = 0;
int levelCount = 4;
bool goingUp = true;
void setup() {
  Serial.begin(115200);
}

void loop() {
  now = millis();
  if (now - lastLevelChange >= levelInterval) {
    lastLevelChange = now;
    analogWrite(ledPin, brightnessLevels[levelIndex]);
    Serial.println(brightnessLevels[levelIndex]);
    if (goingUp) {
      levelIndex++;
      if (levelIndex > levelCount) {
        goingUp = !goingUp;
        levelIndex = levelCount - 1;
      }
    } else {
      levelIndex--;
      if (levelIndex < 0) {
        goingUp = !goingUp;
        levelIndex = 1;
      }
    }
  }
}
