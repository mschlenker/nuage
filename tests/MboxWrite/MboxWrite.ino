
#define BRIDGE_BAUDRATE 19200
#include <Bridge.h>

void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH); 
  delay(1000);           
  digitalWrite(13, LOW);  
  delay(1000);      
  Bridge.begin();
  delay(1000);
  Bridge.put("hello","world"); 
}

void loop() {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(10);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second 
}
