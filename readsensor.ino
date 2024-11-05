#include <Wire.h> 
#include <Adafruit_TSL2591.h>
#include <rgb_lcd.h>
rgb_lcd lcd;
Adafruit_TSL2591 tsl = Adafruit_TSL2591(2591); 



void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); 
}

int Readsensor() {
  uint r= tsl.getLuminosity(TSL2591_VISIBLE);
  Serial.println(r);
 
  
  return r;




}

void loop() {
Readsensor();
// put your main code here, to run repeatedly:

}
