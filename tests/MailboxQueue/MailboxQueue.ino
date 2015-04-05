
// #define BRIDGE_BAUDRATE 19200

#include <Bridge.h>
#include <Console.h>
#include <Mailbox.h>

void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  // Initialize Bridge and Mailbox
  Bridge.begin();
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
