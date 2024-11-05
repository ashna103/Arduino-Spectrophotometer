// define pin numbers for tricolour LED
int Rpin = 9;
int Gpin = 11;
int Bpin = 10;

void setup() {
  pinMode(Rpin, OUTPUT);
  pinMode(Gpin, OUTPUT);
  pinMode(Bpin, OUTPUT);

}

void ledOff() {
  // turns on tricolour LED
  // colour - 0 = red, 1 = green, 2 = blue

  // turn off all LED elements first 
  digitalWrite(Rpin, LOW);
  digitalWrite(Gpin, LOW);
  digitalWrite(Bpin, LOW);
  

}

void loop() {

}
