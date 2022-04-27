#include <Adafruit_NeoPixel.h>

/*************************************************
 * Public Constants
 *************************************************/

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

#define PIN 11
// input pin Neopixel is attached to

#define NUMPIXELS 19
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

int speaker = 9;
int delayTime = 250;

void setup() {
  pixels.begin(); // Initializes the NeoPixel library.
  Serial.begin(9600);
  pinMode(speaker,OUTPUT);
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
      tone(speaker, NOTE_C4);
      delay(delayTime);
      noTone(speaker);
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
      tone(speaker, NOTE_D4);
      delay(delayTime);
      noTone(speaker);
//        Serial.print("two\n");
//        Serial.print("red: ");
//        Serial.println(redColor);
//        Serial.print("green: ");
//        Serial.println(greenColor);
//        Serial.print("blue: ");
//        Serial.println(blueColor); 
    }
  
    else if (buttonC == HIGH){
      //LED is yellow
      redColor = 0;
      greenColor = 255;
      blueColor = 255;
      tone(speaker, NOTE_E4);
      delay(delayTime);
      noTone(speaker);
//        Serial.print("three\n");
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
      tone(speaker, NOTE_F4);
      delay(delayTime);
      noTone(speaker);
//        Serial.print("four\n");
//        Serial.print("red: ");
//        Serial.println(redColor);
//        Serial.print("green: ");
//        Serial.println(greenColor);
//        Serial.print("blue: ");
//        Serial.println(blueColor);
    }

    else if (buttonE == HIGH){
      //LED is Blue
      redColor = 0;
      greenColor = 0;
      blueColor = 255;
      tone(speaker, NOTE_G4);
      delay(delayTime);
      noTone(speaker);
//        Serial.print("five\n");
//        Serial.print("red: ");
//        Serial.println(redColor);
//        Serial.print("green: ");
//        Serial.println(greenColor);
//        Serial.print("blue: ");
//        Serial.println(blueColor);
    }

    else if (buttonF == HIGH){
      //LED is Indigo
      redColor = 100;
      greenColor = 100;
      blueColor = 255;
      tone(speaker, NOTE_A4);
      delay(delayTime);
      noTone(speaker);
//        Serial.print("six\n");
//        Serial.print("red: ");
//        Serial.println(redColor);
//        Serial.print("green: ");
//        Serial.println(greenColor);
//        Serial.print("blue: ");
//        Serial.println(blueColor);
    }

    else if (buttonG == HIGH){
      //LED is Violet
      redColor = 255;
      greenColor = 0;
      blueColor = 255;
      tone(speaker, NOTE_B4);
      delay(delayTime);
      noTone(speaker);
//        Serial.print("seven\n");
//        Serial.print("red: ");
//        Serial.println(redColor);
//        Serial.print("green: ");
//        Serial.println(greenColor);
//        Serial.print("blue: ");
//        Serial.println(blueColor);
    }

//    else{
//      redColor = 255;
//      greenColor = 255;
//      blueColor = 255;
//    }
    
  for(int i=0;i<NUMPIXELS;i++){
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(redColor, greenColor, blueColor));

    pixels.show(); // This sends the updated pixel color to the hardware.
  }
}
