#include <Wire.h> 
#include <Adafruit_TSL2591.h>
Adafruit_TSL2591 tsl = Adafruit_TSL2591(2591); 



void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); 
}

float CalcAbs(uint16_t blank,uint16_t reading){
  
  float trans;
  trans=float(reading/blank);
  float absorb;
  absorb=log10(1/trans);

  return absorb;



}

void loop() {

  // put your main code here, to run repeatedly:
Serial.println(CalcAbs(1000,500)); 
delay(5000);
}
