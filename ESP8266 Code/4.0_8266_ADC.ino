void setup()
{
  Serial.begin(115200);
}
void loop()
{
  // read the input on analog pin 0:
  int ADC_Value=analogRead(A0);
  Serial.print("ADC 10 bit = ");
  Serial.println(ADC_Value); 
  
  // Transform ADC Value to Volt
  float volts =3.30*(float)ADC_Value/1023.00;
  Serial.print("Voltage = ");
  Serial.print(volts,2);
  Serial.println(" V");
  delay(1000); // delay 1 sec
}

