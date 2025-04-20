#include <WiFi.h>

#define RX2 16
#define TX2 17
#define ESP_LED 2

const char* ssid = "Crazyyz";
const char* password = "420420420";

WiFiServer server(80);
bool arduinoLEDState = false;

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RX2, TX2);
  pinMode(ESP_LED, OUTPUT);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    Serial.println("Client connected");
    String request = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        request += c;
        if (c == '\n' && request.endsWith("\r\n\r\n")) {
          break;
        }
      }
    }

    // Simple HTML UI
    String html = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
    html += "<!DOCTYPE html><html><head><title>ESP32 Control</title></head><body>";
    html += "<h2>ESP32 Web Switch</h2>";
    html += "<form action=\"/toggleESP\" method=\"GET\"><button>Toggle ESP32 LED</button></form><br>";
    html += "<form action=\"/toggleARD\" method=\"GET\"><button>Toggle Arduino LED</button></form><br>";
    html += "</body></html>";

    // Toggle logic based on requested URL
    if (request.indexOf("GET /toggleESP") >= 0) {
      digitalWrite(ESP_LED, !digitalRead(ESP_LED));
    }

    if (request.indexOf("GET /toggleARD") >= 0) {
      arduinoLEDState = !arduinoLEDState;
      Serial2.println(arduinoLEDState ? "1" : "0");
    }

    client.print(html);
    delay(1);
    client.stop();
    Serial.println("Client disconnected");
  }
}
