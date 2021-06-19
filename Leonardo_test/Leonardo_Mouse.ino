#include <Mouse.h>

void setup() {
  pinMode(2, OUTPUT);  
  pinMode(3, INPUT_PULLUP);
  //initiate the Mouse library
  Mouse.begin();
}

void loop() {
  //if the button is pressed, send a left mouse click
  if (digitalRead(3) == LOW) {
    Mouse.click();
  }
  delay(1000);
}
