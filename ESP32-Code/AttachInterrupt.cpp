#include <Arduino.h>

#define buttonPin 12 // the number of the pushbutton pin
#define ledPin 2 // the number of the LED pin

/*attachInterrupt(PIN, EXTI_ISR, eadge); */
void EXTI3_ISR()
{
    digitalWrite(ledPin,!digitalRead(ledPin));
    Serial.println("Interrupt from pin 12");
}

void setup()
{
    Serial.begin(115200); // initialize serial:
    pinMode(ledPin,OUTPUT);
    pinMode(buttonPin,INPUT_PULLUP);
    attachInterrupt(buttonPin,EXTI3_ISR,CHANGE);
}

void loop()
{
    delay(250);
}
