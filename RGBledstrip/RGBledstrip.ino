#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pixels(16, 6, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 3

int sensorPin = A0; // select the input pin for LDR
unsigned int sensorValue = 0; // variable to store value coming from LDR
int threshold = 700;

void setup() {
  pixels.begin(); 
}
void loop() {
  pixels.clear(); 
  for(int i=0; i<16; i++) { 
    pixels.setPixelColor(i, pixels.Color(250, 100, 0));
    pixels.show();   
    delay(DELAYVAL);
  }
}
