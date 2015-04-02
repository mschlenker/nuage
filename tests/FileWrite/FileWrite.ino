
#define BRIDGE_BAUDRATE 19200
#include <Bridge.h>
#include <FileIO.h>

void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH); 
  delay(1000);           
  digitalWrite(13, LOW);  
  delay(1000);     
  Bridge.begin(); 
  FileSystem.begin();
  File script = FileSystem.open("/tmp/stuff.txt", FILE_WRITE);
  script.println("Hello world!");
  script.close();  // close the file
  delay(1000);
}

void loop() {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(10);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
}
