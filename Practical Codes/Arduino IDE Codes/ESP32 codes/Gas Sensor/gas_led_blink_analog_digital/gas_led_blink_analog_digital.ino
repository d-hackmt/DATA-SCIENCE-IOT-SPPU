const int gasAnalogPin = 27;         // Analog pin for gas concentration
const int gasDigitalPin = 14;        // Digital output from sensor
const int ledPin = 2;                // LED pin

const int analogThreshold = 100;    // Custom threshold (you can tune this)

void setup() {
  Serial.begin(115200);
  pinMode(gasDigitalPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int analogValue = analogRead(gasAnalogPin);
  int digitalStatus = digitalRead(gasDigitalPin);

  Serial.print("Analog Value: ");
  Serial.print(analogValue);
  Serial.print(" | Digital Status: ");
  Serial.println(digitalStatus == HIGH ? "Gas Detected" : "Clear");

  // Blink LED if gas is detected via digital pin OR analog value is above threshold
  if (digitalStatus == HIGH || analogValue < analogThreshold) {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  } else {
    digitalWrite(ledPin, LOW);  // Turn off LED if no gas
    delay(1000);                // Relaxed check interval
  }
}
