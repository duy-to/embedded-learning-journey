int brightness = 100;
int* a = &brightness;
void setup() {
  Serial.begin(115200);
  Serial.println(brightness);
  Serial.println((uint32_t)&brightness,HEX);
  Serial.println((uint32_t)a,HEX);
   Serial.println(*a);
  *a = 200;
  Serial.println(brightness);
}

void loop() {
  // put your main code here, to run repeatedly:
}
