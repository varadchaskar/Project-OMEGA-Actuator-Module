/*
* File: main.cpp of Project OMEGA Actuator Module
* Author: Varad Chaskar
* Description: This code controls an actuator module using an ESP8266. 
* It connects to a WiFi network using the WiFiManager library and communicates 
* with the ThingSpeak cloud platform to read and control actuators.
* Date: January 28, 2024
* 
* Libraries Required:
* 1. WiFiManager - For handling WiFi configuration via an access point.
* 2. ESP8266WiFi - To enable WiFi functionality on the ESP8266.
* 3. ThingSpeak - To interact with the ThingSpeak cloud for reading and writing data.
*
* Code Functionality:
* - Connects the ESP8266 to a WiFi network using WiFiManager.
* - Reads values from a ThingSpeak channel and controls actuators (LEDs, etc.) based on the values read.
* - Automatically reconnects to WiFi if the connection fails and stores WiFi credentials for future use.
*/

#include <WiFiManager.h>       // WiFiManager for easy WiFi configuration
#include <ESP8266WiFi.h>       // ESP8266 WiFi library for handling WiFi
#include "ThingSpeak.h"        // ThingSpeak library to interact with the ThingSpeak cloud
WiFiClient client;             // Create WiFi client object for ThingSpeak

// ThingSpeak channel and API keys
unsigned long myChannelNumber = 2384399;                 // Channel number for ThingSpeak
const char *myWriteAPIKey = "ELW2NF5Q83OGB39G";          // Write API key for ThingSpeak
const char *myCounterReadAPIKey = "3D8NH4JCI0EDYMIU";    // Read API key for ThingSpeak

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // Set the built-in LED pin as output
  pinMode(0, OUTPUT);           // Set GPIO pin 0 as output
  pinMode(D7, OUTPUT);          // Set GPIO pin D7 as output
  pinMode(D8, OUTPUT);          // Set GPIO pin D8 as output
  pinMode(4, OUTPUT);           // Set GPIO pin 4 as output
  pinMode(5, OUTPUT);           // Set GPIO pin 5 as output
  Serial.begin(115200);         // Start serial communication at 115200 baud rate

  // --- WiFiManager Setup ---
  WiFiManager wm;  // Create a WiFiManager object
  bool res;        // Variable to store WiFi connection result

  // Attempt to connect to WiFi network using WiFiManager
  res = wm.autoConnect("ActuatorModule_AP"); // AP name if no WiFi is configured

  if (!res) {
    // If failed to connect to WiFi, print message and restart ESP8266
    Serial.println("Failed to connect to WiFi");
    digitalWrite(LED_BUILTIN, HIGH);  // Indicate failure by turning on the built-in LED
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
    digitalWrite(LED_BUILTIN, HIGH);
    ESP.restart();  // Restart the ESP8266 for a new attempt
  } else {
    // Successfully connected to WiFi
    Serial.println("Connected to WiFi!");  
    digitalWrite(LED_BUILTIN, LOW);  // Turn off built-in LED to indicate successful connection

    // --- ThingSpeak Setup ---
    ThingSpeak.begin(client);  // Initialize ThingSpeak with WiFi client
  }
}

void loop() {
  // --- Reading and Controlling Actuators via ThingSpeak ---
  digitalWrite(LED_BUILTIN, LOW);  // Keep built-in LED off when running

  // Read data from ThingSpeak channel field 5 and control GPIO pin 5
  int A = ThingSpeak.readLongField(myChannelNumber, 5, myCounterReadAPIKey);
  analogWrite(5, A);  // Set PWM output on pin 5 based on ThingSpeak data

  // Read data from ThingSpeak channel field 6 and control GPIO pin 4
  int B = ThingSpeak.readLongField(myChannelNumber, 6, myCounterReadAPIKey);
  analogWrite(4, B);  // Set PWM output on pin 4 based on ThingSpeak data

  // Read data from ThingSpeak channel field 7 and control GPIO pin 0
  int C = ThingSpeak.readLongField(myChannelNumber, 7, myCounterReadAPIKey);
  analogWrite(0, C);  // Set PWM output on pin 0 based on ThingSpeak data

  // Read data from ThingSpeak channel field 8 and trigger GPIO D7 or D8 based on the value
  int D = ThingSpeak.readLongField(myChannelNumber, 8, myCounterReadAPIKey);

  if (D == 100) {
    // Trigger GPIO D7 in a pattern if D equals 100
    digitalWrite(D7, HIGH);
    delay(500);
    digitalWrite(D7, LOW);
    delay(500);
    digitalWrite(D7, HIGH);
    delay(500);
    digitalWrite(D7, LOW);
    delay(500);
    digitalWrite(D7, HIGH);
    delay(500);
    digitalWrite(D7, LOW);

    // Update ThingSpeak field 8 after the action
    ThingSpeak.writeField(myChannelNumber, 8, 300, myWriteAPIKey);
    delay(500);
  }

  if (D == 200) {
    // Trigger GPIO D8 if D equals 200
    digitalWrite(D8, HIGH);
    delay(500);
    digitalWrite(D8, LOW);

    // Update ThingSpeak field 8 after the action
    ThingSpeak.writeField(myChannelNumber, 8, 300, myWriteAPIKey);
    delay(500);
  }
}
