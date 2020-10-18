#include <Adafruit_TCS34725.h>

#include <Wire.h>
#define TCAADDR 0x70
/* Assign a unique ID to this sensor at the same time */
Adafruit_TCS34725 cSensor1 = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
Adafruit_TCS34725 cSensor2 = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);



// Helper function to select the correct address
void tcaselect(uint8_t i) {
  if (i > 7) return;
 
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();  
}
 
 
void setup(void) 
{
  Serial.begin(9600);
  
  /* Initialise the 1st sensor */
  tcaselect(3);
  if(!cSensor1.begin())
  {
    Serial.println("cSensor1 was not identified");
    while(1);
  }
  
  /* Initialise the 2nd sensor */
  tcaselect(7);
  if(!cSensor2.begin())
  {
    Serial.println("cSensor2 was not identified");
    while(1);
  }
}
 
void loop(void) 
{
  float red, green, blue;

  // selects Sensor 1 from multiplexor
  tcaselect(3);
 
  Serial.print("Sensor #1 - ");
  

  delay(60);  // takes 50ms to read

  cSensor1.getRGB(&red, &green, &blue);
  

  Serial.print("R:\t"); Serial.print(int(red)); 
  Serial.print("\tG:\t"); Serial.print(int(green)); 
  Serial.print("\tB:\t"); Serial.print(int(blue));
  Serial.print("\n");

  // selects Sensor 2 from multiplexor
  tcaselect(7);
  Serial.print("Sensor #2 - ");
  
  delay(60);  // takes 50ms to read

  cSensor2.getRGB(&red, &green, &blue);

  Serial.print("R:\t"); Serial.print(int(red)); 
  Serial.print("\tG:\t"); Serial.print(int(green)); 
  Serial.print("\tB:\t"); Serial.print(int(blue));
  Serial.print("\n");
  
  delay(500);
}
