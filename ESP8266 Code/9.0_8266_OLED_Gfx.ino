#include <Wire.h> 
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET -1

Adafruit_SSD1306 OLED(OLED_RESET);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void setup() {
  OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}
void loop(){
  OLED.clearDisplay(); 
  OLED.setTextColor(WHITE,BLACK);
  int x = 0;
  int y = 0;
  int w = 127;
  int h = 63;
  for(int i=0; i<5;i++){
    OLED.drawRect(i*5,i*5,128-i*10,64-i*10,WHITE);
    delay(250);
    OLED.display();
  }
  OLED.clearDisplay();
  for(int i=0; i<5;i++){
    OLED.drawRect(i*5,i*5,128-i*10,64-i*10,WHITE);
    delay(250);
    OLED.display();
    OLED.clearDisplay();
  }
  OLED.clearDisplay();
  for(int i=0; i<5;i++){
    OLED.drawCircle(64,32,31-i*5,WHITE);
    delay(250);
    OLED.display();
  }
  OLED.clearDisplay();
  for(int i=0; i<5;i++){
    OLED.drawCircle(64,32,31-i*5,WHITE);
    delay(250);
    OLED.display();
    OLED.clearDisplay();
  }
  
}
