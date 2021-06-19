#include "LedControl.h"

LedControl lc=LedControl(11,13,10,4);  // DIN,CLK,CS,Number of LED Module

unsigned long delaytime=100;  // time to updates of the display

void setup() {
  lc.shutdown(0,false);     // go to normal mode
  lc.setIntensity(0,7);     // brightness
  lc.clearDisplay(0);       // clear display
}

/*
 This method will display the characters for the
 word "Arduino" one after the other on the matrix. 
 (you need at least 5x7 leds to see the whole chars)
 */
void writeArduinoOnMatrix() {
  /* here is the data for the characters */
  byte a[5]={B01111110,B10001000,B10001000,B10001000,B01111110};
  byte r[5]={B00111110,B00010000,B00100000,B00100000,B00010000};
  byte d[5]={B00011100,B00100010,B00100010,B00010010,B11111110};
  byte u[5]={B00111100,B00000010,B00000010,B00000100,B00111110};
  byte i[5]={B00000000,B00100010,B10111110,B00000010,B00000000};
  byte n[5]={B00111110,B00010000,B00100000,B00100000,B00011110};
  byte o[5]={B00011100,B00100010,B00100010,B00100010,B00011100};

  /* now display them one by one with a small delay */
  for (int x=0 ; x<5 ; x++) 
    lc.setRow(0,x,a[x]);
  delay(delaytime);
  for (int x=0 ; x<5 ; x++) 
    lc.setRow(0,x,r[x]);
  delay(delaytime);
  for (int x=0 ; x<5 ; x++) 
    lc.setRow(0,x,d[x]);
  delay(delaytime);  
  for (int x=0 ; x<5 ; x++) 
    lc.setRow(0,x,u[x]);
  delay(delaytime);  
  for (int x=0 ; x<5 ; x++) 
    lc.setRow(0,x,i[x]);
  delay(delaytime);  
  for (int x=0 ; x<5 ; x++) 
    lc.setRow(0,x,n[x]);
  delay(delaytime);  
  for (int x=0 ; x<5 ; x++) 
    lc.setRow(0,x,o[x]);
  delay(delaytime);  
 
  lc.setRow(0,0,0);
  lc.setRow(0,1,0);
  lc.setRow(0,2,0);
  lc.setRow(0,3,0);
  lc.setRow(0,4,0);
  delay(delaytime);
}

/*
  This function lights up a some Leds in a row.
 The pattern will be repeated on every row.
 The pattern will blink along with the row-number.
 row number 4 (index==3) will blink 4 times etc.
 */
void rows() {
  for(int row=0;row<8;row++) {
    delay(delaytime);
    lc.setRow(0,row,B10100000);
    delay(delaytime);
    lc.setRow(0,row,(byte)0);
    for(int i=0;i<row;i++) {
      delay(delaytime);
      lc.setRow(0,row,B10100000);
      delay(delaytime);
      lc.setRow(0,row,(byte)0);
    }
  }
}

/*
  This function lights up a some Leds in a column.
 The pattern will be repeated on every column.
 The pattern will blink along with the column-number.
 column number 4 (index==3) will blink 4 times etc.
 */
void columns() {
  for(int col=0;col<8;col++) {
    delay(delaytime);
    lc.setColumn(0,col,B10100000);
    delay(delaytime);
    lc.setColumn(0,col,(byte)0);
    for(int i=0;i<col;i++) {
      delay(delaytime);
      lc.setColumn(0,col,B10100000);
      delay(delaytime);
      lc.setColumn(0,col,(byte)0);
    }
  }
}

/* 
 This function will light up every Led on the matrix.
 The led will blink along with the row-number.
 row number 4 (index==3) will blink 4 times etc.
 */
void single() {
  for(int row=0;row<8;row++) {
    for(int col=0;col<8;col++) {
      delay(delaytime);
      lc.setLed(0,row,col,true);
      delay(delaytime);
      for(int i=0;i<col;i++) {
        lc.setLed(0,row,col,false);
        delay(delaytime);
        lc.setLed(0,row,col,true);
        delay(delaytime);
      }
    }
  }
}

void loop() { 
  writeArduinoOnMatrix();
  rows();
  columns();
  single();
}
