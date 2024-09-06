
#include <Wire.h>
#include <rgb_lcd.h>
rgb_lcd lcd;

void displaysetup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
lcd.setCursor(0,0);

}

void display (String message, int line)
{
lcd.setCursor(0,line);
lcd.print(message);

}

void setup() {
  displaysetup();
}

void loop() {
  // put your main code here, to run repeatedly:

display("Black",1);
delay(1000);
display("Brown",0);
delay(1000);
}
