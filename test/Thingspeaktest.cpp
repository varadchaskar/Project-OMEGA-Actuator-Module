#include "ThingSpeak.h" // Include the ThingSpeak library for communication with the ThingSpeak cloud service
#include "ESP8266WiFi.h"

WiFiClient client; // Create a WiFi client object, which will be used for the ThingSpeak connection

// Define ThingSpeak channel and API keys
unsigned long myChannelNumber = 2384399; // Your ThingSpeak channel number where data will be written/read
const char *myWriteAPIKey = "ELW2NF5Q83OGB39G"; // API key for writing data to the ThingSpeak channel
const char *myCounterReadAPIKey = "3D8NH4JCI0EDYMIU"; // API key for reading data from the ThingSpeak channel

void setup() {
  // After connecting to WiFi, initialize the ThingSpeak communication
  // ThingSpeak requires an active WiFi connection, which is managed by the WiFiClient object
  ThingSpeak.begin(client); // Start ThingSpeak communication using the WiFi client
}

void loop() {
  // Reading data from specific fields on the ThingSpeak channel
  // These fields store data that has been previously uploaded to ThingSpeak

  // Read a long integer value from field 5 of the specified ThingSpeak channel
  int A = ThingSpeak.readLongField(myChannelNumber, 5, myCounterReadAPIKey);
  // After reading the value, the analog output on pin 5 is set based on the data retrieved from ThingSpeak
  analogWrite(5, A); // Set pin 5 analog value to the retrieved data (A)

  // Read a long integer value from field 6 of the specified ThingSpeak channel
  int B = ThingSpeak.readLongField(myChannelNumber, 6, myCounterReadAPIKey);
  // Set the analog output on pin 4 based on the data retrieved from ThingSpeak
  analogWrite(4, B); // Set pin 4 analog value to the retrieved data (B)

  // Read a long integer value from field 7 of the specified ThingSpeak channel
  int C = ThingSpeak.readLongField(myChannelNumber, 7, myCounterReadAPIKey);
  // Set the analog output on pin 0 based on the data retrieved from ThingSpeak
  analogWrite(0, C); // Set pin 0 analog value to the retrieved data (C)

  // Read a long integer value from field 8 of the specified ThingSpeak channel
  int D = ThingSpeak.readLongField(myChannelNumber, 8, myCounterReadAPIKey);

  // Conditional behavior based on the value read from field 8
  if (D == 100) {
    // If the value from field 8 is 100, blink the D7 pin's connected actuator (e.g., an LED)
    digitalWrite(D7, HIGH); // Turn on pin D7
    delay(500);             // Wait for 500 milliseconds
    digitalWrite(D7, LOW);  // Turn off pin D7
    delay(500);             // Repeat the blinking pattern
    digitalWrite(D7, HIGH);
    delay(500);
    digitalWrite(D7, LOW);
    delay(500);
    digitalWrite(D7, HIGH);
    delay(500);
    digitalWrite(D7, LOW);

    // Update field 8 on ThingSpeak with a new value (300) using the write API key
    ThingSpeak.writeField(myChannelNumber, 8, 300, myWriteAPIKey); // Write the new value (300) to field 8
    delay(500); // Delay to avoid rapid updates
  }

  // Another conditional behavior based on the value from field 8
  if (D == 200) {
    // If the value from field 8 is 200, trigger the D8 pin's actuator
    digitalWrite(D8, HIGH); // Turn on pin D8
    delay(500);             // Wait for 500 milliseconds
    digitalWrite(D8, LOW);  // Turn off pin D8

    // Update field 8 on ThingSpeak with a new value (300)
    ThingSpeak.writeField(myChannelNumber, 8, 300, myWriteAPIKey); // Write the new value (300) to field 8
    delay(500); // Delay to avoid rapid updates
  }
}
