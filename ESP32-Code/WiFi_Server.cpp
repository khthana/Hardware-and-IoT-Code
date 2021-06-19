
#include <Arduino.h>
#include <WiFi.h>
#include "Wire.h"
#include "Adafruit_SSD1306.h"
#include "Adafruit_GFX.h"

const char ssid[] = "ssid";
const char password[] = "password";
const char* target_hostname = "www.google.com";

IPAddress ip_result;

byte mac[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

const uint16_t port = 8888;

/* fix password case
char server_ip[] = "10.0.0.10";
IPAddress ip(10, 0, 0, 10);
IPAddress gateway(10, 0, 0, 1);
IPAddress subnet(255, 255, 255, 0);
*/

WiFiServer server(port);

WiFiClient Client[2];

void setup()
{
    Serial.begin(115200);

    /*********** Connect to WiFi network ***********/
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);

    //if not need fix ip please comment
    //WiFi.config(local_ip, gateway, subnet);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(100);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");

    // Start the server
    server.begin();
    Serial.print("Local ip is : "); // Print the IP address
    Serial.println(WiFi.localIP());
    Serial.print("Port is :");
    Serial.println(port);
    Serial.print("Subnet Mark : ");
    Serial.println(WiFi.subnetMask());
    Serial.print("Default Gateway : ");
    Serial.println(WiFi.gatewayIP());
    Serial.print("MAC Address is :");
    WiFi.macAddress(mac);
    Serial.print("MAC: ");
    Serial.print(mac[5],HEX);
    Serial.print(":");
    Serial.print(mac[4],HEX);
    Serial.print(":");
    Serial.print(mac[3],HEX);
    Serial.print(":");
    Serial.print(mac[2],HEX);
    Serial.print(":");
    Serial.print(mac[1],HEX);
    Serial.print(":");
    Serial.println(mac[0],HEX);
    Serial.print("Channel : ");
    Serial.println(WiFi.channel());
    Serial.print("RSSI : ");
    Serial.println(WiFi.RSSI());
    WiFi.hostByName(target_hostname,ip_result);
    Serial.print("DNS lookup for ");
    Serial.print(target_hostname);
    Serial.print(" is : ");
    Serial.println(ip_result);
    //WiFi.hostname("test");
    //Serial.print("My hostname is : ");
    //Serial.println(WiFi.hostname());

    byte numSsid = WiFi.scanNetworks();
    String s = "** Scan Networks **\r\n";
    s += "SSID List:";
    s += numSsid;
    s += "\r\n";
    for (int thisNet = 0; thisNet<numSsid; thisNet++) {
        s += thisNet;
        s += ") ";
        s += WiFi.RSSI(thisNet);
        s += "  AP:  ";
        s += WiFi.SSID(thisNet);
        s += "\r\n";
    }
    Serial.println(s);
    /*********************************************/

    Serial.println("Now Server Start.");
}

void loop()
{
    if (server.hasClient()) {
      for (int i=0; i<2 ; i++) {
        if (!Client[i] || !Client[i].connected()) {
          //if (Client[i]) Client[i].stop();
          Client[i] = server.available();
          Serial.print("New Client : ");
          Serial.print(String(i+1)+ " - ");
          Serial.println(Client[i].remoteIP());
          continue;
        }
      }
      WiFiClient TempClient = server.available();
      TempClient.stop(); // Reject New Client
    }
    for (int i=0;i<2;i++) {
      if (Client[i] && Client[i].connected()) {
        if (Client[i].available()) {
          Serial.println(Client[i].readStringUntil('\n'));
          Client[i].println("<OK>");
        }
      }
    }
    /*
    WiFiClient client = server.available();
    if (client) {

        Serial.println("new client");

        while(true)
        {
            while(client.available())
            {
                char data = client.read();
                Serial.write(data);
                client.print(data);
            }

            if(server.hasClient()) {
                return;
            }
        }
    }
    */
}
