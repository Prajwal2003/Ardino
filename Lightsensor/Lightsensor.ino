int sensorPin = A0; // select the input pin for LDR
unsigned int sensorValue = 0; // variable to store value coming from LDR
int threshold = 700;
void setup()
{
 pinMode(13, OUTPUT);
 Serial.begin(9600); // start serial for output - for testing
}
void loop()
{
 // read the value from the ldr:
 sensorValue = analogRead(sensorPin); 
 Serial.println(sensorValue); 
 if(sensorValue > threshold) digitalWrite(13, HIGH); 
 else digitalWrite(13, LOW); 
}