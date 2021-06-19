#include <Mouse.h>

void setup() {
  pinMode(2,OUTPUT);
  digitalWrite(2,LOW);
  //The switch that will initiate the Mouse press
  //The switch that will terminate the Mouse press  pinMode(3, INPUT_PULLUP);

  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);  
  //initiate the Mouse library
  Mouse.begin();

}

void loop() {
  //if the switch attached to pin 2 is closed, press and hold the left mouse button
  if (digitalRead(3) == LOW) {
    Mouse.press(MOUSE_RIGHT);
  }
  if (digitalRead(4) == LOW) {  //if the switch attached to pin 3 is closed, release the left mouse button
    Mouse.release(MOUSE_RIGHT);
  }    
}
