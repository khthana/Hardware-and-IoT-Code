#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <M2M_LM75A.h>

#define OLED_RESET 7
#define OLED_SA0   8
Adafruit_SSD1306 display(OLED_RESET, OLED_SA0);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

M2M_LM75A lm75a;

void setup()
{
  lm75a.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
}

void loop()
{
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print("Temp. in C: ");
  display.print(lm75a.getTemperature());
  display.println(" *C");
  display.print("Temp. in F: ");
  display.print(lm75a.getTemperatureInFarenheit());
  display.println(" *F");
  display.display();
  
  // Shutdown/Wake up
  display.println("Shutting down");
  lm75a.shutdown();
  display.print("Is shutdown: ");
  display.println(lm75a.isShutdown());
  delay(5000);
  display.display();
  
  display.println("Waking up");
  lm75a.wakeup();
  display.print("Is shutdown: ");
  display.println(lm75a.isShutdown());
  delay(2000);
  display.display();
}
