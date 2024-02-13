#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> 
#endif
#define PIN       6 
#define NUMPIXELS 16 
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL  3
const int groundpin = A0; 
const int powerpin  = A2; 
int tempPin   = A1;
float tempC;
float reading;
int sensorPin = A3; 
unsigned int sensorValue = 0;
int threshold = 700;

void setup() {

  pinMode(9, OUTPUT);
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
  #endif
  pixels.begin();
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  pinMode(groundpin, OUTPUT);
  pinMode(powerpin, OUTPUT);
  digitalWrite(groundpin, LOW);
  digitalWrite(powerpin, HIGH);
  analogReference(DEFAULT); 

}


void loop() {

  sensorValue = analogRead(sensorPin); 
  sensorValue = analogRead(sensorPin); 
  Serial.println(sensorValue);
  delay(100);

  reading = analogRead(tempPin);
  reading = analogRead(tempPin);
  tempC = reading / 2.048;
  Serial.print("Temperature: ");
  Serial.println(tempC);

if(tempC > 32){
  if(sensorValue < 700){
  digitalWrite(9, LOW); 
}
else
{
  digitalWrite(9, HIGH);
}
  for(int i=0; i<NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(250, 0, 0));
    pixels.show();
    delay(100);
  }
}
else
if(tempC < 26)
{
  if(sensorValue < 700){
    digitalWrite(9, LOW); 
}
else
{
  digitalWrite(9, HIGH);
}
  for(int i=0; i<NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(0, 0, 250));
    pixels.show();  
    delay(100);
  }
}
  else
  {
    if(sensorValue < 700){
      digitalWrite(9, LOW); 
}
else
{
  digitalWrite(9, HIGH);
}
    for(int i=0; i<NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(0, 250, 0));
    pixels.show();
    delay(100);
  }
}                   
}

