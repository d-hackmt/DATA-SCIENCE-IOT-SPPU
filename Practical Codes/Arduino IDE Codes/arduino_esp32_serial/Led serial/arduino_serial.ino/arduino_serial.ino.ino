void setup() {
  // Initialize the built-in LED pin as an output
  pinMode(13, OUTPUT);
  
  // Start the serial communication with ESP32 and PC
  Serial.begin(9600);  // Serial Monitor (PC)
  Serial.println("Arduino Uno ready to receive messages from ESP32...");
}

void loop() {
  // Check if data is available from ESP32
  if (Serial.available()) {
    char incomingByte = Serial.read();  // Read the incoming byte
    
    // Print the received byte to the serial monitor for debugging
    Serial.print("Message Received: ");
    Serial.println(incomingByte);
    
    // If the message is '1', turn the LED ON
    if (incomingByte == '1') {
      digitalWrite(13, HIGH);  // Turn LED ON
    }
    // If the message is '0', turn the LED OFF
    else if (incomingByte == '0') {
      digitalWrite(13, LOW);   // Turn LED OFF
    }
  }
}
