#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

#define BLYNK_PRINT Serial
int pin = 16;

#define DHTPIN 17
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

unsigned long previousMillis = 0;

char auth[] = "token";

char ssid[] = "ssid";
char pass[] = "password";

void setup() {
  pinMode(pin, OUTPUT);
  pinMode(pin, HIGH);

  Serial.begin(115200);
  dht.begin();

  delay(10);
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, pass);
  int wifi_ctr = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi connected");

  Blynk.begin(auth, ssid, pass);
}

void loop(){
    Blynk.run();

    unsigned long currentMillis = millis();
      if (currentMillis - previousMillis >= 10000) {
        previousMillis = currentMillis;
        float t = dht.readTemperature();
        if (!isnan(t)) {
          Blynk.virtualWrite(V0, t);
        }
        float h = dht.readHumidity();
        if (!isnan(h)) {
          Blynk.virtualWrite(V1, h);
        }
        Serial.println(t);
      }
}
