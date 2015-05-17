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
#include <Console.h>

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
  Bridge.begin();
  // Alternative notation with Paul Stoffregens modified version of the Bridge
  // Bridge.begin(Serial, BRIDGE_BAUDRATE);
  Console.begin();
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  Console.println("Hallo Welt!");
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(10);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
}
