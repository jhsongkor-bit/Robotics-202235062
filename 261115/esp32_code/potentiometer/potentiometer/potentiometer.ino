#define BUZZER_PIN 5
#define POT_PIN 39

#define BUZZER_FREO 2000
#define RESOLUTION 8

void setup() {
  ledcAttach(BUZZER_PIN, BUZZER_FREO, RESOLUTION);

  Serial.begin(112500);
}

void loop() {
  int value = analogRead(POT_PIN);
  
  int buzzerSound = map(value, 0, 1023, 0, 255);
  
  Serial.println(value);
  analogWrite(BUZZER_PIN, buzzerSound);
  delay(50);
}