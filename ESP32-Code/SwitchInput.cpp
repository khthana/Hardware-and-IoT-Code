#include <Arduino.h>

#define button 12 // switch input Active Low
#define pressed HIGH

void setup()
{
    Serial.begin(115200);
    pinMode(button,INPUT_PULLUP);
}

int i=0;
void loop()
{
    bool ReadSwitch = digitalRead(button);
    if(ReadSwitch == pressed)
    {
        Serial.print(i++);
        Serial.println(" Pressed Switch.");
        delay(500);
    }
}
