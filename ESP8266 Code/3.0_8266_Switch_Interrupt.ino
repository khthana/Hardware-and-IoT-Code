#define D0 16 // USER LED Wake
#define D1 0 // FLASH
#define buttonPin1 D1 // the number of the pushbutton pin
#define ledPin D0 // the number of the LED pin

void setup()
{
  Serial.begin(9600); // initialize serial:
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin1,INPUT_PULLUP);
  attachInterrupt(buttonPin1,ISR_D1,CHANGE);
}

void loop()
{
  delay(250);
}

void ISR_D1()
{
  digitalWrite(ledPin,!digitalRead(ledPin));
  Serial.println("Interrupt from pin D1");
}
