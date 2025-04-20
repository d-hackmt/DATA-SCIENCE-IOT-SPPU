const int gasSensorPin = 27; // Analog input pin for gas sensor
const int ledPin = 2;        // Output pin for LED (onboard or external)

const int threshold = 100;  // Adjust based on your sensor's values

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int gasValue = analogRead(gasSensorPin); // Read analog gas sensor value
  Serial.print("Gas Sensor Value: ");
  Serial.println(gasValue);

  if (gasValue < threshold) {
    digitalWrite(ledPin, HIGH);  // Turn on LED
    delay(2000);
    digitalWrite(ledPin, LOW);   // Turn off LED
    delay(2000);                  // Blink every 0.5 sec when above threshold
  } else {
    digitalWrite(ledPin, LOW);   // Keep LED off
    delay(1000);                 // Slow loop to avoid spamming serial
  }
}
