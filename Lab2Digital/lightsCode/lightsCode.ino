#include <Adafruit_NeoPixel.h>

//include the library
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

//define the digital pin that the LED strip is connected to
#define PIN 8

//the first parameter is the number of LEDs you have - change for your strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(4, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin(); //we always need to do this
  strip.show(); // Initialize all pixels to 'off'
  pinMode(11, INPUT);
}

void loop() {
  //Start with all LEDs on 
  
  int current_value = digitalRead(11);
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, 0, 150, 150); //set to blue, takes RGB vals 0-255
    strip.show();
  }

  //When the button is pressed the strip will slowly change from blue to purple
  if(current_value == HIGH){
      Serial.print("color");
      for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, 150, 0, 150); //set to purple
      strip.show();
      delay(500);
    }

      for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, 0, 150, 150); //set to blue
      delay(500);
    }
  }
}
