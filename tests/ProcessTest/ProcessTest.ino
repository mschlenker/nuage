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
#include <Process.h>

void setup() {
  // Initialize Bridge
  Bridge.begin();
  // Alternative notation with Paul Stoffregens modified version of the Bridge
  // Bridge.begin(Serial, BRIDGE_BAUDRATE);
  // Initialize Serial
  Console.begin();
  delay(5000);
  // run various example processes
  runCurl();
  runCpuInfo();
  runLots();
}

void loop() {
  runLots();
  delay(3000); 
}

void runLots() {
  Process p;        // Create a process and call it "p"
  p.begin("ls");  // Process that launch the "curl" command
  p.addParameter("/usr"); // Add the URL parameter to "curl"
  p.addParameter("/opt");
  p.addParameter("/tmp");
  p.addParameter("/bin");
  p.addParameter("/sbin");
  p.addParameter("/usr/local");
  p.addParameter("/usr/share");
  p.addParameter("/usr/share/nuage");
  p.run();      // Run the process and wait for its termination
  while (p.available()>0) {
    char c = p.read();
    Console.print(c);
  }
}

void runCurl() {
  // Launch "curl" command and get Arduino ascii art logo from the network
  // curl is command line program for transferring data using different internet protocols
  Process p;        // Create a process and call it "p"
  p.begin("curl");  // Process that launch the "curl" command
  p.addParameter("http://arduino.cc/asciilogo.txt"); // Add the URL parameter to "curl"
  p.run();      // Run the process and wait for its termination

  // Print arduino logo over the Serial
  // A process output can be read with the stream methods
  while (p.available()>0) {
    char c = p.read();
    Console.print(c);
  }
  // Ensure the last bit of data is sent.
  // Serial.flush();
}

void runCpuInfo() {
  // Launch "cat /proc/cpuinfo" command (shows info on Atheros CPU)
  // cat is a command line utility that shows the content of a file
  Process p;        // Create a process and call it "p"
  p.begin("cat");   // Process that launch the "cat" command
  p.addParameter("/proc/cpuinfo"); // Add the cpuifo file path as parameter to cut
  p.run();      // Run the process and wait for its termination

  // Print command output on the Serial.
  // A process output can be read with the stream methods
  while (p.available()>0) {
    char c = p.read();
    Console.print(c);
  }
  // Ensure the last bit of data is sent.
  // Serial.flush();
}
 
