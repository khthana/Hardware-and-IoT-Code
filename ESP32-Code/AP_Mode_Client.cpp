
#include <Arduino.h>
#include <WiFi.h>

const char ssid[] = "ESP32";
const char password[] = "";
byte mac[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

WiFiClient client;

char server_ip[] = "192.168.4.1";
const uint16_t port = 8888;

void setup()
{
   Serial.begin(115200);
   Serial.println();
   Serial.print("Connecting to ");
   Serial.println(ssid);

   WiFi.begin(ssid, password);

     while (WiFi.status() != WL_CONNECTED) {
        delay(200);
         Serial.print(".");
     }
     Serial.println("");
     Serial.println("WiFi connected with Router");
     if (client.connect(server_ip,port))
      {
           Serial.println("client connected server");
          client.print("Hello I'm Client from ");
          client.println(WiFi.localIP());
          client.println();
       }

       Serial.print("Local ip is : ");
       Serial.println(WiFi.localIP());
       Serial.print("Port is:"); Serial.println(port);

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
    char  data = client.read();   Serial.write(data);
  }
  client.println("Hello"); delay(1000);
}
