#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ADXL345.h>

#define OLED_RESET 7
#define OLED_SA0   8
Adafruit_SSD1306 display(OLED_RESET, OLED_SA0);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

ADXL345 adxl; //variable adxl is an instance of the ADXL345 library

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  adxl.powerOn();
}

void loop() {

  //Boring accelerometer stuff
  int x, y, z;
  adxl.readXYZ(&x, &y, &z); //read the accelerometer values and store them in variables  x,y,z
  // Output x,y,z values
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0); 
  display.print("values of X , Y , Z: ");
  display.print(x);
  display.print(" , ");
  display.print(y);
  display.print(" , ");
  display.println(z);

  double xyz[3];
  double ax, ay, az;
  adxl.getAcceleration(xyz);
  ax = xyz[0];
  ay = xyz[1];
  az = xyz[2];
  display.print("X=");
  display.print(ax);
  display.println(" g");
  display.print("Y=");
  display.print(ay);
  display.println(" g");
  display.print("Z=");
  display.print(az);
  display.println(" g");
  display.display();  
  delay(1000);
}
