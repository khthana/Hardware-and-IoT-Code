
#include <Arduino.h>
#include <WiFi.h>

#define AP_Name "ESP32"

WiFiServer server(8888); // TCP Server Port

String line;

void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_AP); // AP Mode
    WiFi.softAP(AP_Name);

    server.begin(); // Start Server
}

void loop() {
    WiFiClient client = server.available();
    if (!client)
        return;

    Serial.println("New client");
    while (client.connected()) {
        if (client.available()) {
            Serial.println(client.readStringUntil('\n'));
        }
    }

    delay(1);
    client.stop();
    Serial.println("Client disconnect"); 
}
