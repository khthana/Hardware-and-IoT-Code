#include <Arduino.h>

int ADC_Pin = 34;

void setup()
{
    Serial.begin(115200);
}
void loop()
{
// read the input on analog pin 0:
    int sensorValue=analogRead(ADC_Pin);
    Serial.print("ADC 12 bit = ");
    Serial.println(sensorValue); // print out the value you read:
    float volts =3.30*(float)sensorValue/4096.00;
    Serial.print(" , Voltage = ");
    Serial.print(volts,2);
    Serial.println(" V");
    delay(1000); // delay in between reads for stability
}
