#include <Arduino.h>

#include <WiFi.h>

const char* ssid = "NTNU-IOT";
const char* password = "";





// put function declarations here:
void connectWiFi();

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