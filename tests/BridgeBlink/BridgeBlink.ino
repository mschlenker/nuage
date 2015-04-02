
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
