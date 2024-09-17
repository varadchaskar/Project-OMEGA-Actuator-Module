#include <WiFiManager.h> // Include the WiFiManager library, which simplifies connecting to WiFi networks
#include <ESP8266WiFi.h> // Include the ESP8266 WiFi library for basic WiFi functionality

void setup() {
  Serial.begin(115200); // Initialize serial communication at a baud rate of 115200 for debugging

  // Create an instance of WiFiManager
  // WiFiManager helps manage WiFi connections and allows us to easily connect to a WiFi network without hardcoding credentials
  WiFiManager wm;

  bool res; // Variable to store the result of the WiFi connection attempt

  // autoConnect() is a function of WiFiManager that attempts to connect to a saved WiFi network.
  // If no saved network is found, it sets up an access point (AP) with the provided SSID ("ASAA").
  // The user can connect to this AP with their phone or computer and configure the WiFi settings.
  res = wm.autoConnect("ASAA"); // Attempt to connect to WiFi with the SSID "ASAA"
  
  // Check if the WiFi connection was unsuccessful
  if (!res) {
    // If connection to the WiFi network failed:
    // Print an error message to the serial monitor for debugging purposes
    Serial.println("Failed to connect");
    
    // Blink the built-in LED to indicate an error. This is a visual cue for failed connection.
    // Turn the LED on and off in 1-second intervals
    digitalWrite(LED_BUILTIN, HIGH); // Turn on the built-in LED
    delay(1000); // Wait for 1 second
    digitalWrite(LED_BUILTIN, LOW);  // Turn off the built-in LED
    delay(1000); // Wait for another 1 second
    digitalWrite(LED_BUILTIN, HIGH); // Turn on the LED again

    // Restart the ESP8266 to retry the WiFi connection after the failure
    ESP.restart(); // This forces a reboot to try connecting again after failure
  } else {
    // If the WiFi connection was successful:
    
    // Print a success message to the serial monitor
    Serial.println("Connected... Yeey :)");

    // Turn off the built-in LED to indicate that the connection was successful
    digitalWrite(LED_BUILTIN, LOW); // Turn off the LED as we are connected to WiFi

    // Now the device is connected to the internet, and further actions such as cloud communication can be initialized.
  }
}

void loop() {
    
}
