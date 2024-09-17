# Project-OMEGA-Actuator-Module
Hydroponics Based Precision Farming with Feature Optimization, Actuator Module

<h2>WiFiManager Library</h2>
<p>
The <code>WiFiManager</code> library is used to simplify the process of connecting the ESP8266 to a WiFi network. It provides a convenient interface for configuring WiFi credentials without hardcoding them into the code. When the ESP8266 cannot connect to a saved WiFi network, it will create an Access Point (AP) that users can connect to and input their WiFi credentials via a captive portal.
</p>
<ul>
    <li><strong>autoConnect()</strong>: This function is called to automatically attempt connecting to a previously saved WiFi network. If the device cannot connect, it sets up an AP for manual WiFi configuration.</li>
    <li><strong>Access Point (AP) Mode</strong>: If no saved WiFi network is found or the connection fails, the ESP8266 creates a local WiFi network (AP) where users can enter the SSID and password of their WiFi network via a web interface.</li>
    <li><strong>WiFi Credentials</strong>: After users input the WiFi credentials through the captive portal, the ESP8266 stores them in its non-volatile memory for future connections.</li>
    <li><strong>Error Handling</strong>: If the connection to WiFi fails, the code restarts the ESP8266 after a brief indication using the built-in LED. This ensures the device attempts to reconnect to the WiFi automatically.</li>
</ul>

<p>Using WiFiManager eliminates the need to hardcode WiFi credentials, making the device more flexible and easier to configure in various network environments.</p>

<h2>ThingSpeak Library</h2>
<p>
The <code>ThingSpeak</code> library provides an easy way to connect the ESP8266 to the <a href="https://thingspeak.com/" target="_blank">ThingSpeak</a> cloud platform for IoT applications. ThingSpeak is a cloud-based platform that allows you to collect, store, analyze, and act on sensor data from IoT devices. With this library, you can both read from and write to a ThingSpeak channel, which acts as a repository for sensor and actuator data.
</p>
<ul>
    <li><strong>ThingSpeak.begin(client)</strong>: Initializes the ThingSpeak connection using a <code>WiFiClient</code> object. This prepares the ESP8266 for communication with the cloud service.</li>
    <li><strong>readLongField()</strong>: This function is used to read data from a specific field in a ThingSpeak channel. Each field in a channel can store a different type of data (e.g., sensor readings, actuator states).</li>
    <li><strong>writeField()</strong>: This function writes data to a specified field in a ThingSpeak channel. It requires a channel number, field number, value, and an API key for secure access.</li>
    <li><strong>WiFiClient</strong>: ThingSpeak communication requires a valid internet connection, which is handled by the <code>WiFiClient</code> object. This object is responsible for maintaining the connection to ThingSpeak's servers.</li>
</ul>

<p>Using the ThingSpeak library, you can easily send and retrieve data from the cloud, enabling your ESP8266 to interact with web-based dashboards and IoT applications.</p>
