#define RX_PIN 16  // RX pin connected to Arduino TX
#define TX_PIN 17  // TX pin connected to Arduino RX

void setup() {
  // Initialize Serial for communication with PC (Serial Monitor)
  Serial.begin(9600);  // For debugging on PC
  Serial.println("ESP32 ready to send messages to Arduino...");
  
  // Initialize Serial2 for communication with Arduino
  Serial2.begin(9600, SERIAL_8N1, RX_PIN, TX_PIN);  // Baud rate, 8N1, RX, TX
}

void loop() {
  // Send "1" to Arduino to turn the LED ON
  Serial2.println("1");
  delay(1000);  // Wait for 1 second

  // Send "0" to Arduino to turn the LED OFF
  Serial2.println("0");
  delay(1000);  // Wait for 1 second
}
