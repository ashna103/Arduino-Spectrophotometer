////////////////////////////////////////////////
// define global variables
////////////////////////////////////////////////

// define pin numbers for tricolour LED
#include <Wire.h> 
#include <Adafruit_TSL2591.h>
#include <rgb_lcd.h>
rgb_lcd lcd;
Adafruit_TSL2591 tsl = Adafruit_TSL2591(2591); 
int Rpin = 9;
int Gpin = 11;
int Bpin = 10;
int colour = 0;
uint16_t blank;
uint16_t reading;
int Zpin = 5;
int Wpin =6;
int Rdpin = 12;
String message; 
int line;

////////////////////////////////////////////////
// define custom functions
////////////////////////////////////////////////

void ledOn(int colour) {
  // turns on tricolour LED
  // colour - 0 = red, 1 = green, 2 = blue

  // turn off all LED elements first 
  digitalWrite(Rpin, HIGH);
  digitalWrite(Gpin, HIGH);
  digitalWrite(Bpin, HIGH);
  
  // turn on one LED element 
  if (colour == 0) {
    digitalWrite (Rpin, LOW);
    }
  else if (colour == 1) {
    digitalWrite(Gpin, LOW);
  }
  else if (colour == 2) {
    digitalWrite(Bpin, LOW);
  }
}


float CalcAbs(uint16_t blank,uint16_t reading){
  
  float trans;
  trans=float(reading)/float(blank);
  float absorb;
  absorb=log10(1/trans);

  return absorb;

}

void cycleWave() {

if (colour == 0) {
  colour = 1;
}
else if (colour == 1) {
  colour =2;
}
else if (colour == 2) {
  colour = 0;
  }
}

int Readsensor(){
  uint16_t r= tsl.getLuminosity(TSL2591_FULLSPECTRUM);
  Serial.println(r);
 
  return r;
}


void displaysetup(){
  // put your setup code here, to run once:
lcd.begin(16,2);
lcd.setCursor(0,0);
}

void display (String message, int line) {
lcd.setCursor(0,line);
lcd.print(message);
}


void ledOff() {
  // turns on tricolour LED
  // colour - 0 = red, 1 = green, 2 = blue

  // turn off all LED elements first 
  digitalWrite(Rpin, HIGH);
  digitalWrite(Gpin, HIGH);
  digitalWrite(Bpin, HIGH);
}

////////////////////////////////////////////////
// main functions
///////////////////////////////////////////////
void Read() {
  ledOn(colour);
  delay(500);
  Readsensor();
  ledOff();
  reading = Readsensor();
  CalcAbs(blank,reading);
  message= CalcAbs(blank,reading);
  display(message, 0);
}

void Wave() {
  cycleWave();
}

void Zero() {
  ledOn(colour);
  Readsensor();
  ledOff();
  blank = Readsensor();
  display("0", 2);

}


////////////////////////////////////////////////
// main loops
///////////////////////////////////////////////

void setup() {
  // put your setup code here, to run once:
  pinMode(Rpin, OUTPUT);
  pinMode(Gpin, OUTPUT);
  pinMode(Bpin, OUTPUT);
  Serial.begin(9600);
  displaysetup();
  pinMode(Zpin, INPUT_PULLUP);
  pinMode(Wpin, INPUT_PULLUP);
  pinMode(Rdpin,INPUT_PULLUP);

// setup sensor
  tsl.setTiming(TSL2591_INTEGRATIONTIME_100MS);
  tsl.setGain(TSL2591_GAIN_MED); 

}

void loop() {
  // put your main code here, to run repeatedly:
 if (digitalRead(Zpin) == LOW){
   Zero();
 } 
if (digitalRead(Rdpin) == LOW){
  Read();
  } 
if (digitalRead(Wpin) == LOW){
  Wave();
 }

}
