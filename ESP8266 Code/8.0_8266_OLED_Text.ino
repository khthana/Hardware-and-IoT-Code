#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET -1

Adafruit_SSD1306 OLED(OLED_RESET);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void setup()
{
    Serial.begin(115200);
    OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C); // initialize with the I2C addr 0x3C (for the 128x64)
}

void loop()
{
    OLED.clearDisplay(); // clear display
    OLED.setTextColor(WHITE); // set text color
    OLED.setCursor(10,0);
    OLED.setTextSize(1);
    OLED.println("Hello");
    OLED.setCursor(10,15);
    OLED.println("World");
    OLED.display();
}
