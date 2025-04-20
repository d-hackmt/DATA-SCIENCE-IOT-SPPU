void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n'); // Read until newline
    command.trim(); // Remove any unwanted whitespace
    if (command == "1") {
      digitalWrite(13, HIGH);
    } else if (command == "0") {
      digitalWrite(13, LOW);
    }
  }
}
