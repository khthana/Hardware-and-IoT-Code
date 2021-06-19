#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <IRremote.h>
#include <IRremoteInt.h>

#define VR_Pin A0
#define LDR_Pin A1
#define LM35_Pin A2

#define Sw1 2
#define Sw2 3
#define LED_Red 12
#define LED_Blue 13
#define DHT11_Pin 4
#define Buzzer_Pin 5
#define IR_Pin 6
#define RGB_Red 9
#define RGB_Green 10
#define RGB_Blue 11

#define DHTTYPE DHT11 

DHT dht(DHT11_Pin, DHTTYPE);
IRrecv receiver(IR_Pin);
decode_results results; 

void setup() 
{
    // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
    dht.begin();
    receiver.enableIRIn();
    pinMode(Sw1, INPUT);  
    pinMode(Sw2, INPUT);    
    pinMode(IR_Pin, INPUT);   
    pinMode(RGB_Red, OUTPUT);
    pinMode(RGB_Green, OUTPUT);
    pinMode(RGB_Blue, OUTPUT);  
    pinMode(LED_Red, OUTPUT);
    pinMode(LED_Blue, OUTPUT);  
    pinMode(Buzzer_Pin, OUTPUT);    
}

void setColor(int red, int green, int blue)
{
    analogWrite(RGB_Red, red);
    analogWrite(RGB_Green, green);
    analogWrite(RGB_Blue, blue);  
}

void showRGB(int mil)
{
    setColor(1, 0, 0);  // red lowest brightness
    delay(mil);
    setColor(50, 0, 0);  // red
    delay(mil);
    setColor(140, 0, 0);  // red
    delay(mil);
    setColor(255, 0, 0);  // red
    delay(mil);
    setColor(0, 255, 0);  // green
    delay(mil);
    setColor(0, 0, 255);  // blue
    delay(mil);
    setColor(255, 255, 0);  // yellow
    delay(mil);  
    setColor(80, 0, 80);  // purple
    delay(mil);
    setColor(255, 50, 0);  // Orange
    delay(mil);
}  

void showLED(){
    digitalWrite(LED_Red, HIGH);
    delay(500);
    digitalWrite(LED_Red, LOW);
    delay(500);   
    digitalWrite(LED_Blue, HIGH);
    delay(500);
    digitalWrite(LED_Blue, LOW);
    delay(500);         
}

float readHumidity()
{
    float humidity = dht.readHumidity();
    return(humidity);
}

float readTemperature()
{
    float temperature = dht.readTemperature();
    return (temperature);
}

float readLDR()
{
    float ldrValue = analogRead(LDR_Pin);
    float ldrVoltage = ldrValue * (5.0 / 1023.0);

    return (ldrVoltage);
}

float readVR()
{
    float vrValue = analogRead(VR_Pin);
    float vrVoltage = vrValue * (5.0 / 1023.0);    
    return (vrVoltage);
}

float readLM35()
{
    float lmValue = analogRead(LM35_Pin);
    float temperature = lmValue * 0.48828125;
    return (temperature);
}

int readSwitch(int pin)
{
    int buttonState = digitalRead(pin);  
    return (buttonState);
}
     
void loop() 
{
    // print out the Variable resistor value you read:
    Serial.print("Variable resistor : ");
    Serial.println(readVR());
    Serial.print("LDR value : ");
    Serial.println(readLDR());
    Serial.print("LM35 Temperature : ");
    Serial.println(readLM35()); 

    Serial.print("Humidity : ");
    Serial.println(readHumidity());
    Serial.print("Temperature : ");    
    Serial.println(readTemperature());

    if(receiver.decode(&results)) {             //  Decode the button code and put it in "results" variable
        Serial.println(results.value, HEX);       //  Print the code as a hexadecimal value
        receiver.resume();               
    }

    showRGB(500);
    showLED();

    if (readSwitch(Sw1)==LOW) { Serial.println("Switch 1 Pressed"); }
    if (readSwitch(Sw2)==LOW) { Serial.println("Switch 2 Pressed"); }
}
