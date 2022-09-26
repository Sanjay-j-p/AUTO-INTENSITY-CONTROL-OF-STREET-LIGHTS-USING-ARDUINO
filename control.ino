#include <LiquidCrystal.h> 
// initialize the library with the numbers of the interface pins 
LiquidCrystal lcd (12, 11, 5, 4, 3, 2); int potPin = 1; // Analog pin 0 
for the LED brightness potentiometer 
int ledPin = 6; // LED Digital Pin with PWM 
int potValue = 0; // variable to store the value coming from the 
potentiometer 
int brightness = 0; // converts the potValue into a 
brightness int pBari = 0; // progress bar int i = 0; 
// for loop 
//progress bar character for brightness 
byte pBar [8] = {B11111, B11111, B11111, B11111, 
B11111, B11111, B11111,}; void setup () { 
Serial.begin(9600); // setup our led as an OUTPUT 
pinMode (ledPin, OUTPUT); 
 // set up the LCD's number of columns and rows: 
 lcd. begin (16, 2); 
// Print a message on the LCD 
lcd.print(" LED Brightness"); //Create 
the progress bar character 
lcd.createChar(0, pBar); 
} 
void loop() { 
 // clears the LCD screen 
lcd.clear(); 
 // Print a message to the LCD 
lcd.print("LED BRIGHTNESS"); //set 
the cursor to line number 2 
lcd.setCursor(0,1); 
 // read the value from the potentiometer potValue 
= analogRead(potPin); 
 // turns the potValue into a brightness for the LED potValue 
= constrain(potValue,40,400); 
potValue = map(potValue,40,400,300,0); 
//lights up the LED according to the brightness 
analogWrite(ledPin,potValue); 
// turns the brightness into a percentage for the bar 
pBari=map(potValue, 0, 255, 1, 16); 
 Serial.println(pBari); 
//prints the progress bar for 
(i=1; i<pBari; i++) 
 { 
 lcd.setCursor(i, 1); 
lcd.write(byte(0)); 
 } 
 // delays 750 ms delay(750); 
}
