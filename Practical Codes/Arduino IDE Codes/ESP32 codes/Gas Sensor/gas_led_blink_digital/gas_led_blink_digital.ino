const int gasSensorDigitalPin = 14;  // D14 - Digital pin from gas sensor
const int ledPin = 2;                // Onboard LED (or external LED)

void setup() {
  Serial.begin(115200);             // Start serial monitor for debugging
  pinMode(gasSensorDigitalPin, INPUT); // Sensor pin as input
  pinMode(ledPin, OUTPUT);             // LED pin as output
}

void loop() {
  int gasStatus = digitalRead(gasSensorDigitalPin); // Read gas sensor

  if (gasStatus == HIGH) {  // Gas detected
    Serial.println("🔥 Gas Detected! Blinking LED...");
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  } else {
    Serial.println("✅ No Gas Detected.");
    digitalWrite(ledPin, LOW); // Ensure LED is off
    delay(1000);
  }
}
