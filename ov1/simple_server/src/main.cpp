#include <Arduino.h>
#include <AsyncTCP.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>

const char* ssid = "NTNU-IOT";
const char* password = "";



AsyncWebServer server(80);

void connectWiFi();

String HTMLdata = "<!DOCTYPE html>"
  "<html>"
  "<head>"
  "<title>Sensordata</title>"
  "<meta http-equiv='refresh' content='0.5'>"
  "</head>"
  "<body>"
  "<h1>Sensordata</h1>"
  "</body>"
  "</html>";


void setup() {
  Serial.begin(115200);
  connectWiFi();
}

void loop() {
  if(WiFi.status() != WL_CONNECTED)
  {
    Serial.println("Lost connection:");
    connectWiFi();
  }

  
}


void connectWiFi()
{
  Serial.println("Connecting to wifi");
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print(".");
  }
  String localWiFi = String(WiFi.localIP());
  Serial.println("Successfully connected to" + localWiFi);
}