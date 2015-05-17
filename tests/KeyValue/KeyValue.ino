/*
 * This sketch requires the Arduino IDE (from arduino.cc) version 1.6.4 or later. 
 * Alternatively Paul Stoffregens version of the Bridge library may be used with
 * Arduino 1.5.x or later. See https://github.com/PaulStoffregen/Bridge for git
 * access!
 *
 * If you want to tinker with Nuage in non standard setups use Pauls Bridge
 * library, since it allows you to specify arbitary serial ports for use with the
 * Bridge. 
 */

// Define the baud rate to use - Arduino 1.6.4 or later
#define BRIDGE_BAUDRATE 19200

#include <Bridge.h>

void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH); 
  delay(1000);           
  digitalWrite(13, LOW);  
  delay(1000);      
  Bridge.begin();
  // Alternative notation with Paul Stoffregens modified version of the Bridge
  // Bridge.begin(Serial, BRIDGE_BAUDRATE);
  delay(1000);
  Bridge.put("hello","world"); 
}

void loop() {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(10);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second 
}
