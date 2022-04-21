#include <Adafruit_NeoPixel.h>

#define PIN 11
// input pin Neopixel is attached to

#define NUMPIXELS 8
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
      chase(pixels.Color(255, 0, 0)); // Red
      chase(pixels.Color(0, 255, 0)); // Green
      chase(pixels.Color(0, 0, 255)); // Blue

    }
  
    else if (buttonB == HIGH){
      pixels.setPixelColor(2, 255, 255, 0);



    }
  
    else if (buttonC == HIGH){
      //LED is yellow
      redColor = 0;
      greenColor = 255;
      blueColor = 255;

    }

    else if (buttonD == HIGH){
      //LED is Green
      redColor = 0;
      greenColor = 255;
      blueColor = 0;

    }

    else if (buttonE == HIGH){
      //LED is Blue
      redColor = 0;
      greenColor = 0;
      blueColor = 255;


    }

    else if (buttonF == HIGH){
      //LED is Indigo
      redColor = 100;
      greenColor = 100;
      blueColor = 255;

    }

    else if (buttonG == HIGH){
      //LED is Violet
      redColor = 255;
      greenColor = 0;
      blueColor = 255;

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

static void chase(uint32_t c) {
  for(uint16_t i=0; i<pixels.numPixels()+4; i++) {
      pixels.setPixelColor(i  , c); // Draw new pixel
      pixels.setPixelColor(i-4, 0); // Erase pixel a few steps back
      pixels.show();
      delay(25);
  }
}
