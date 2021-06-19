
#include <Arduino.h>
#include <WiFi.h>
#include "Wire.h"
#include "Adafruit_SSD1306.h"
#include "Adafruit_GFX.h"

#define OLED_RESET -1

Adafruit_SSD1306 OLED(OLED_RESET);

const char ssid[] = "ssid";
const char password[] = "password";
byte mac[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

WiFiClient client;

char server_ip[] = "192.168.1.2";
const uint16_t port = 8888;

void setup()
{
    Serial.begin(115200);
    OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C); // initialize with the I2C addr 0x3D (for the 128x64)
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    OLED.clearDisplay();
    OLED.setTextColor(WHITE);

    while (WiFi.status() != WL_CONNECTED) {
          delay(200);
          Serial.print(".");
     }
     Serial.println("");
     Serial.println("WiFi connected with Router");
     if (client.connect(server_ip,port)) {
          Serial.println("client connected server");
          client.print("Hello I'm Client from ");
          client.println();
     }

     Serial.print("Local ip is : ");
     Serial.println(WiFi.localIP());
     Serial.print("Port is:"); Serial.println(port);

     OLED.setCursor(10,0);
     OLED.setTextSize(1);
     client.println(WiFi.localIP());
     OLED.println(WiFi.localIP());
     OLED.display();

     Serial.print("MAC Address is :"); WiFi.macAddress(mac);
     Serial.print("MAC: ");  Serial.print(mac[5],HEX); Serial.print(":"); Serial.print(mac[4],HEX);
     Serial.print(":"); Serial.print(mac[3],HEX);
     Serial.print(":"); Serial.print(mac[2],HEX);
     Serial.print(":"); Serial.print(mac[1],HEX);
     Serial.print(":"); Serial.println(mac[0],HEX);
}

void loop()
{
    while(client.available()) {
        char  data = client.read();
        Serial.write(data);
  }
  client.println("Hello"); delay(1000);
}
