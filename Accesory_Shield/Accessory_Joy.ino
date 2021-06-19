#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define    KEY_UP        A1
#define    KEY_DOWN      A5
#define    KEY_LEFT      A3
#define    KEY_RIGHT     A2
#define    KEY_ENTER     A4

#define OLED_RESET 7
#define OLED_SA0   8
Adafruit_SSD1306 display(OLED_RESET, OLED_SA0);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void setup()   {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  pinMode(KEY_UP, INPUT); digitalWrite(KEY_UP, HIGH);
  pinMode(KEY_DOWN, INPUT); digitalWrite(KEY_DOWN, HIGH);
  pinMode(KEY_LEFT, INPUT); digitalWrite(KEY_LEFT, HIGH);
  pinMode(KEY_RIGHT, INPUT); digitalWrite(KEY_RIGHT, HIGH);
  pinMode(KEY_ENTER, INPUT); digitalWrite(KEY_ENTER, HIGH);
  showString(" ");
}

void showString(String str)
{
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println(str);
  display.display();
}

void loop() {
  if (digitalRead(KEY_UP) == LOW) {
    showString("Up Pressed");
    digitalWrite(KEY_UP, HIGH);
    delay(1000);
  }
  else if (digitalRead(KEY_DOWN) == LOW) {
    showString("Down Pressed");
    digitalWrite(KEY_DOWN, HIGH);
    delay(1000);    
  }  
  else if (digitalRead(KEY_LEFT) == LOW) {
    showString("Left Pressed");
    digitalWrite(KEY_LEFT, HIGH);
    delay(1000);    
  }    
  else if (digitalRead(KEY_RIGHT) == LOW) {
    showString("Right Pressed");
    digitalWrite(KEY_RIGHT, HIGH);
    delay(1000);    
  }    
  else if (digitalRead(KEY_ENTER) == LOW) {
    showString("Enter Pressed");
    digitalWrite(KEY_ENTER, HIGH);
    delay(1000);    
  }     
  showString(" ");
  delay(200);
}
