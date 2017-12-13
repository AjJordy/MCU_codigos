// color swirl! connect an RGB LED to the PWM pins as indicated
// in the #defines
// public domain, enjoy!

#define GREENPIN 5
 
#define FADESPEED 5     // make this higher to slow down
 
void setup() {  
  Serial.begin(9600);
  pinMode(GREENPIN, OUTPUT); 
}
 
void loop() {
  int g;
  // fade from red to yellow
  for (g = 0; g < 256; g++) { 
    analogWrite(GREENPIN, g);
    Serial.println(g);
    delay(FADESPEED);
  }  
  // fade from teal to blue
  for (g = 255; g > 0; g--) { 
    analogWrite(GREENPIN, g);
    Serial.println(g);
    delay(FADESPEED);
  } 
}
