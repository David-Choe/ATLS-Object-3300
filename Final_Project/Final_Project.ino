#include <Adafruit_NeoPixel.h>

#define PIN 11
// input pin Neopixel is attached to

#define NUMPIXELS 4
// number of neopixels in Ring

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 50; 
// timing delay

int redColor = 255;
int greenColor = 255;
int blueColor = 255;

int buttonA = 0;
int buttonB = 0;
int buttonC = 0;
int buttonD = 0;
int buttonE = 0;
int buttonF = 0;
int buttonG = 0;

//Notes control of each button
int toneA = 440;
int toneB = 494;
int toneC = 523;
int toneD = 587;
int toneE = 659;
int toneF = 698;
int toneG = 784;

int speaker = 9;
int duration = 500;

void setup() {
  pixels.begin(); // Initializes the NeoPixel library.
  Serial.begin(9600);
}

void loop() {
  buttonA = digitalRead(2);
  buttonB = digitalRead(3);
  buttonC = digitalRead(4);
  buttonD = digitalRead(5);
  buttonE = digitalRead(6);
  buttonF = digitalRead(7);
  buttonG = digitalRead(8);

    if (buttonA == HIGH){
      //LED is red
      redColor = 255;
      greenColor = 0;
      blueColor = 0;
      tone(speaker, toneA, duration);
        Serial.print("one\n");
        Serial.print("red: ");
        Serial.println(redColor);
        Serial.print("green: ");
        Serial.println(greenColor);
        Serial.print("blue: ");
        Serial.println(blueColor);
    }
  
    else if (buttonB == HIGH){
      //LED is orange
      redColor = 200;
      greenColor = 100;
      blueColor = 0;
      tone(speaker, toneB, duration);
        Serial.print("two\n");
        Serial.print("red: ");
        Serial.println(redColor);
        Serial.print("green: ");
        Serial.println(greenColor);
        Serial.print("blue: ");
        Serial.println(blueColor); 
    }
  
    else if (buttonC == HIGH){
      //LED is yellow
      redColor = 0;
      greenColor = 255;
      blueColor = 255;
      tone(speaker, toneC, duration);
        Serial.print("three\n");
        Serial.print("red: ");
        Serial.println(redColor);
        Serial.print("green: ");
        Serial.println(greenColor);
        Serial.print("blue: ");
        Serial.println(blueColor);
    }

    else if (buttonD == HIGH){
      //LED is Green
      redColor = 0;
      greenColor = 255;
      blueColor = 0;
      tone(speaker, toneD, duration);
        Serial.print("four\n");
        Serial.print("red: ");
        Serial.println(redColor);
        Serial.print("green: ");
        Serial.println(greenColor);
        Serial.print("blue: ");
        Serial.println(blueColor);
    }

    else if (buttonE == HIGH){
      //LED is Blue
      redColor = 0;
      greenColor = 0;
      blueColor = 255;
      tone(speaker, toneE, duration);
        Serial.print("five\n");
        Serial.print("red: ");
        Serial.println(redColor);
        Serial.print("green: ");
        Serial.println(greenColor);
        Serial.print("blue: ");
        Serial.println(blueColor);
    }

    else if (buttonF == HIGH){
      //LED is Indigo
      redColor = 100;
      greenColor = 100;
      blueColor = 255;
      tone(speaker, toneF, duration);
        Serial.print("six\n");
        Serial.print("red: ");
        Serial.println(redColor);
        Serial.print("green: ");
        Serial.println(greenColor);
        Serial.print("blue: ");
        Serial.println(blueColor);
    }

    else if (buttonG == HIGH){
      //LED is Violet
      redColor = 255;
      greenColor = 0;
      blueColor = 255;
      tone(speaker, toneG, duration);
        Serial.print("seven\n");
        Serial.print("red: ");
        Serial.println(redColor);
        Serial.print("green: ");
        Serial.println(greenColor);
        Serial.print("blue: ");
        Serial.println(blueColor);
    }

    else{
      redColor = 255;
      greenColor = 255;
      blueColor = 255;
    }
    
  for(int i=0;i<NUMPIXELS;i++){
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(redColor, greenColor, blueColor));

    pixels.show(); // This sends the updated pixel color to the hardware.
  }
}
