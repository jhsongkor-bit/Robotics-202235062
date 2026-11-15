#define BUZZER_PIN 5
#define POT_PIN 39

#define BUZZER_FREQ 2000
#define RESOLUTION 8

void setup() {
  ledcAttach(BUZZER_PIN, BUZZER_FREQ, RESOLUTION);

  Serial.begin(115200);
}

void loop() {
  int value = analogRead(POT_PIN);

  int buzzerSound = map(value, 0, 4095, 0, 255);

  Serial.println(value);

  ledcWrite(BUZZER_PIN, buzzerSound);

  delay(50);
}