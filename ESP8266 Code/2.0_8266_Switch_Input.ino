#define D8 10 // Mapping pin of NodeMCU with ESP8266
#define button D8 // switch input Active Low
#define pressed LOW

void setup()
{
  Serial.begin(9600);
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

