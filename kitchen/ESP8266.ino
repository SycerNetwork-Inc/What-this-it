#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "";
const char* pass = "";

SoftwareSerial arduinoSerial(D2, D3);

void setup() {
  Serial.begin(9600);
  arduinoSerial.begin(9600);
  pinMode(D2, INPUT);
  pinMode(D3, OUTPUT);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Connecting...");
    Serial.printf("Connection Status: %d\n", WiFi.status());
    delay(1000);
  }

  Serial.print("Wi-Fi connected.");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  while (arduinoSerial.available() > 0) {
    String data = arduinoSerial.readStringUntil('\n');
    Serial.println(data);
  }
}
    
