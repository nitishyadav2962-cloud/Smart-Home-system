#include <WiFi.h>

const char* ssid = "YourWiFiName";
const char* password = "YourWiFiPassword";

WiFiServer server(80);
int ledPin = 26;
bool ledState = LOW;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    String request = client.readStringUntil('\r');
    client.flush();

    if (request.indexOf("/ON") != -1) {
      ledState = HIGH;
      digitalWrite(ledPin, ledState);
    } 
    else if (request.indexOf("/OFF") != -1) {
      ledState = LOW;
      digitalWrite(ledPin, ledState);
    }

    // HTML web page
    String html = "<!DOCTYPE html><html><body>";
    html += "<h2>ESP32 LED C";