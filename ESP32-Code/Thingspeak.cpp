#include <Arduino.h>
#include "DHT.h"
#include <WiFi.h>

const char* ssid = "ssid";
const char* pass = "password";

#define DHTPIN 17 // กำหนดขา Data เพื่อรับข้อมูลจาก DHT22
#define DHTTYPE DHT22 
DHT dht(DHTPIN, DHTTYPE); 

// ThingSpeak Settings //
char thingSpeakAddress[] = "api.thingspeak.com";
String writeAPIKey = "Write API Key"; 
WiFiClient client;

void setup() {
  Serial.begin(115200);
  dht.begin();
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.print("IP address.....");
  Serial.println(WiFi.localIP());
}

void loop () {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  String temp = (String) t; 
  String hum = (String) h; 

  String data = "field1=" + temp + "&field2=" + hum; 

  if (client.connect(thingSpeakAddress, 80)) {
    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: "+writeAPIKey+"\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(data.length());
    client.print("\n\n");
    client.print(data); 
  }

  delay(5000);
}
