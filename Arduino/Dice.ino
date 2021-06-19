
//bits representing numerals 0-9
const byte numeral[11]= {
B11111100, //0
B01100000, //1
B11011010, //2
B11110010, //3
B01100110, //4
B10110110, //5
B00111110, //6
B11100000, //7
B11111110, //8
B11100110, //9
B00000000, //shows nothing
};

const byte hooray_bit[10]= {
B10000000, //0
B01000000, //1
B00100000, //2
B00010000, //3
B00001000, //4
B00000100, //5
B00000010, //6
B00000000, //shows nothing
};

//pins for each segment (g-a) on the 7 segment LED display with the corresponding arduino connection
const int segmentPins[8]= {7,12,11,5,6,8,9,10};
const int GUESS_BUTTON_PIN = 4;
const int START_BUTTON_PIN = 3;

const unsigned int DEBOUNCE_DELAY = 20;

boolean start_state;
boolean old_start_buttonState = HIGH;

boolean guess_state;
boolean old_guess_buttonState = HIGH;

int guess = 0;

void setup()
{
  for (int i=0; i < 8; i++)
    {
      pinMode(segmentPins[i], OUTPUT);
    }
  pinMode(GUESS_BUTTON_PIN, INPUT_PULLUP);
  pinMode(START_BUTTON_PIN, INPUT_PULLUP);
  randomSeed(analogRead(A0));
  
}

void loop()
{
  handle_guess_button();
  handle_start_button();
}

void handle_guess_button() {

  guess_state = digitalRead(GUESS_BUTTON_PIN);

  if ((guess_state == LOW) && (guess_state != old_guess_buttonState)){
    guess = (guess % 6) + 1; 
    output_result(guess);
    delay(DEBOUNCE_DELAY);
  }
  old_guess_buttonState = guess_state;
}

void handle_start_button() {
  start_state = digitalRead(START_BUTTON_PIN);

  if ((start_state == LOW) && (old_start_buttonState == HIGH)){
    random_show();
    const int result = random(1, 7);
    output_result(result);
    delay(1000);
    if (guess > 0) {
      if (result == guess) {
        hooray();
      } else {
        boo();
      }
    }
    delay(2000);
    guess = 0;

    delay(DEBOUNCE_DELAY);
  }
  old_start_buttonState = start_state;
}

void output_result (int number)
{
boolean isBitSet;

  for (int segment=0; segment < 8; segment++)
  {
    isBitSet= bitRead(numeral[number], segment);
    digitalWrite(segmentPins[segment], isBitSet);
  }
}

void random_show() {
  boolean isBitSet;

  output_result(10);
  for (int t=0; t <3; t++) {
    for (int n=0; n < 6; n++) {
      for (int segment=0; segment < 8; segment++)
      {
        isBitSet= bitRead(hooray_bit[n], segment);
        digitalWrite(segmentPins[segment], isBitSet);
        delay(10);
      }
    }
  }
  output_result(10);
}

void hooray() {
  boolean isBitSet;  
     for (int n=0; n < 6; n++) {
      for (int segment=0; segment < 8; segment++)
      {
        isBitSet= bitRead(0b11101110, segment);
        digitalWrite(segmentPins[segment], isBitSet);
        delay(100);
      }  
      output_result(10);
      delay(100);
    }
}

void boo() {
  for (unsigned int i = 0; i < 10; i++) {
    output_result(0);
    delay(100);
    output_result(10);
    delay(100);
  }
}
