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
#include <Mailbox.h>

void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  // Initialize Bridge and Mailbox
  Bridge.begin();
  // Alternative notation with Paul Stoffregens modified version of the Bridge
  // Bridge.begin(Serial, BRIDGE_BAUDRATE);
  Mailbox.begin();
  Console.begin();
  digitalWrite(13, HIGH);
  Console.println("Mailbox Read Message\n");
  Console.println("The Mailbox is checked every 10 seconds. The incoming messages will be shown below.\n");
}

void loop() {
  String message;

  // if there is a message in the Mailbox
  if (Mailbox.messageAvailable())
  {
    // read all the messages present in the queue
    while (Mailbox.messageAvailable())
    {
      Mailbox.readMessage(message);
      Console.println(message);
    }

    Console.println("Waiting 10 seconds before checking the Mailbox again");
  }

  // wait 10 seconds
  delay(10000);
}
