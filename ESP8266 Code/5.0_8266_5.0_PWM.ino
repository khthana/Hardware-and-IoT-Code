#define D0 16 // USER LED Wake
#define LED_Pin D0

void setup()
{
  pinMode(LED_Pin,OUTPUT);
  digitalWrite(LED_Pin,LOW);
  analogWrite(LED_Pin,512);  // Duty Cycle 50 Percent
}
void loop()
{
  for (int f =250; f <=1000; f++)   {
    analogWriteFreq(f);     // Change Frequency of PWM to Dim
    delay(5);
  }
}
