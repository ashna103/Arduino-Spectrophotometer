// define pin numbers for tricolour LED
int Rpin = 9;
int Gpin = 11;
int Bpin = 10;

void setup() {
  pinMode(Rpin, OUTPUT);
  pinMode(Gpin, OUTPUT);
  pinMode(Bpin, OUTPUT);

}

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

void loop() {
  ledOn(0);
  delay(1000);
  ledOn(1);
  delay(1000);
  ledOn(2);
  delay(1000);
}
