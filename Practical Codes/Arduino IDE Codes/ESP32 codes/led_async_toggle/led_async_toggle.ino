#include <WiFi.h>
#include <ESPAsyncWebServer.h>

// Replace with your network credentials
const char* ssid = "Divesh";
const char* password = "12345678";

// Set GPIO pin for LED
const int ledPin = 2;

// Create AsyncWebServer on port 80
AsyncWebServer server(80);

// Variable to store LED state
bool ledState = false;

// HTML Page stored in PROGMEM
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <title>ESP32 LED Control</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    body { text-align: center; font-family: sans-serif; }
    button { padding: 20px; font-size: 20px; }
  </style>
</head>
<body>
  <h1>ESP32 LED Control</h1>
  <p>LED is: <strong><span id="state">%LED_STATE%</span></strong></p>
  <button onclick="toggleLED()">Toggle LED</button>

  <script>
    function toggleLED() {
      fetch("/toggle")
        .then(response => response.text())
        .then(state => {
          document.getElementById("state").innerText = state;
        });
    }
  </script>
</body>
</html>
)rawliteral";

// Processor function for placeholder replacement
String processor(const String& var) {
  if (var == "LED_STATE") {
    return ledState ? "ON" : "OFF";
  }
  return "";
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi..");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConnected! IP Address: " + WiFi.localIP().toString());

  // Serve HTML page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest* request){
    request->send_P(200, "text/html", index_html, processor);
  });

  // Toggle LED via AJAX call
  server.on("/toggle", HTTP_GET, [](AsyncWebServerRequest* request){
    ledState = !ledState;
    digitalWrite(ledPin, ledState ? HIGH : LOW);
    request->send(200, "text/plain", ledState ? "ON" : "OFF");
  });

  server.begin();
}

void loop() {
  // Nothing needed here for async server
}
