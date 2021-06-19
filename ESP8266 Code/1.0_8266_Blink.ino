#define D0 16
#define LED D0

void setup()
{
  pinMode(LED,OUTPUT); // setup output
}

void loop()
{
  digitalWrite(LED,HIGH); // Pin D0 is HIGH
  delay(250);
  digitalWrite(LED,LOW); // Pin D0 is LOW
  delay(250);
}
