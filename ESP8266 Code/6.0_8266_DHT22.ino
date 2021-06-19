#include "DHT.h"

#define D4 2
#define DHTPIN D4  // DHT Pin

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(115200); 
  dht.begin();
}

void loop()
{
  // Wait a few seconds between measurements. 
  delay(2000);
  
  float h = dht.readHumidity();         // Read humidity
  float t = dht.readTemperature();      // Read temperature as Celsius (the default) 
  float f = dht.readTemperature(true);  // Read temperature as Fahrenheit (isFahrenheit = true) 

  // Check if any reads failed and exit early (to try again). 
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!"); 
    return;
  }
  // Heat Index คือ ความร้อนที่ร่างกายรู้สึก อันเนื่องมาจากผลของความชื้น 
  float hif = dht.computeHeatIndex(f, h); // Compute heat index in Fahrenheit (the default) 
  float hic = dht.computeHeatIndex(t, h, false); // Compute heat index in Celsius (isFahreheit = false) 
  
  Serial.print("Humidity: "); 
  Serial.print(h); 
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);  
  Serial.print(" *C "); 
  Serial.print(f);  
  Serial.println(" *F\t "); 
  Serial.print("Heat index: "); 
  Serial.print(hic); 
  Serial.print(" *C "); 
  Serial.print(hif); 
  Serial.println(" *F");

}
