// Define the LED pin (use GPIO 2 by default)
#define LED_PIN 2

void setup() {
  // Initialize the LED pin as output
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);   // Turn the LED on
  delay(1000);                   // Wait for 1 second
  digitalWrite(LED_PIN, LOW);    // Turn the LED off
  delay(1000);                   // Wait for 1 second
}
