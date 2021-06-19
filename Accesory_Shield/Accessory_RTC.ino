#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ds3231.h>

#define OLED_RESET 7
#define OLED_SA0   8
Adafruit_SSD1306 display(OLED_RESET, OLED_SA0);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

ts t; //ts is a struct findable in ds3231.h

void setup() {
  Wire.begin(); //start i2c (required for connection)
  DS3231_init(DS3231_INTCN); //register the ds3231 (DS3231_INTCN is the default address of ds3231, this is set by macro for no performance loss)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  t.sec = 00;   t.min = 30;  t.hour = 10;
  t.mday = 7;   t.mon = 10;  t.year = 2019;
  DS3231_set(t);
}

void loop() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);  
  
  DS3231_get(&t); //get the value and pass to the function the pointer to t, that make an lower memory fingerprint and faster execution than use return
  
  display.print("Day : ");
  display.print(t.mon); //just print some data
  display.print("/");
  display.print(t.mday);
  display.print("/");
  display.println(t.year);
  display.print("Hour : ");
  if (t.hour < 10) display.print("0"); display.print(t.hour);
  display.print(":");
  if (t.min < 10) display.print("0"); display.print(t.min);
  display.print(".");
  if (t.sec < 10) display.print("0"); display.println(t.sec);
#ifdef CONFIG_UNIXTIME
  display.print("Timestamp : ");
  display.print(t.unixtime);
#endif
  display.println();
  display.display();
  delay(1000);
}
