#include "LedControl.h"
#include "FontLEDClock.h" // Font library

LedControl lc=LedControl(11,13,10,4);  // DIN,CLK,CS,Number of LED Module
uint8_t intensity = 1;

unsigned long delaytime=50;  // time to updates of the display

void setup() {
  int devices=lc.getDeviceCount();  // find no of LED modules
  //we have to init all devices in a loop
  for(int address=0;address<devices;address++) {  // set up each device 
    lc.shutdown(address,false);
    lc.setIntensity(address,8);
    lc.clearDisplay(address);
  }
}

void test() {
  int devices=lc.getDeviceCount();  // find no of LED modules
  
  for(int row=32;row>=0;row--) {
    for(int col=0;col<8;col++) {
        delay(delaytime);
        plot(row,col,true);
        delay(delaytime);
        plot(row,col,false);
    }
  }  
}

//plot a point on the display
void plot (uint8_t x, uint8_t y, uint8_t value) {

  //select which matrix depending on the x coord
  uint8_t address;
  if (x >= 0 && x <= 7)   { address = 3; }
  if (x >= 8 && x <= 15)  { address = 2; x = x - 8; }
  if (x >= 16 && x <= 23) { address = 1; x = x - 16;}
  if (x >= 24 && x <= 31) { address = 0; x = x - 24;}

  if (value == 1) {
    lc.setLed(address, y, x, true);
  } else {
    lc.setLed(address, y, x, false);
  }
}

//clear screen
void clear_display() {
  for (uint8_t address = 0; address < 4; address++) {
    lc.clearDisplay(address);
  }
}

//fade screen down
void fade_down() {

  //fade from global intensity to 1
  for (uint8_t i = intensity; i > 0; i--) {
    for (uint8_t address = 0; address < 4; address++) {
      lc.setIntensity(address, i);
    }
    delay(30); //change this to change fade down speed
  }

  clear_display(); //clear display completely (off)

  //reset intentsity to global value
  for (uint8_t address = 0; address < 4; address++) {
    lc.setIntensity(address, intensity);
  }
}

void test_all_led(){
    for (byte x = 0; x <= 31; x++) {
      for (byte y = 0; y <= 7; y++) {
        plot(x, y, 1);
        delay(10);
    }
  }
}

void put_tiny_char(byte x, byte y, char c)
{
  byte dots;
  if (c >= 'A' && c <= 'Z' || (c >= 'a' && c <= 'z') ) { c &= 0x1F; }  // A-Z maps to 1-26 
  else if (c >= '0' && c <= '9') { c = (c - '0') + 32; }
  else if (c == ' ') { c = 0;  } // space 
  else if (c == '.') { c = 27; } // full stop 
  else if (c == ':') { c = 28; } // colon 
  else if (c == '\''){ c = 29; } // single quote mark 
  else if (c == '!') { c = 30; } // single quote mark 
  else if (c == '?') { c = 31; } // single quote mark 

  for (byte col = 0; col < 3; col++) {
    dots = pgm_read_byte_near(&mytinyfont[c][col]);
    for (char row = 0; row < 5; row++) {
      if (dots & (16 >> row))
        plot(x + col, y + row, 1);
      else
        plot(x + col, y + row, 0);
    }
  }
}

void loop() { 
  
  char ver_a[9] = "Hello";  
  byte i = 0;

  while (ver_a[i]) {
    put_tiny_char((i * 4), 1, ver_a[i]);
    delay(35);
    i++;
  }
  delay(2000);
  
  //test_all_led();
  //lear_display();
  
}
