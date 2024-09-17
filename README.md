<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Project OMEGA Actuator Module - README</title>
</head>
<body>

<h1>Project OMEGA Actuator Module</h1>
<h3>Original Project: Hydroponics Based Precision Farming with Feature Optimization</h3>

<p>This repository contains the source code for the Actuator Module, which is part of the original project titled "Hydroponics Based Precision Farming with Feature Optimization". This project is designed to operate actuators in a hydroponic farming system based on sensor readings obtained from the cloud. The code is implemented using an ESP8266, WiFiManager for WiFi configuration, and ThingSpeak for cloud communication.</p>

<h2>Project Overview</h2>
<p>The <strong>Project OMEGA Actuator Module</strong> controls various actuators (such as pumps, lights, or fans) in a precision farming environment. The system reads data from the cloud (ThingSpeak), such as water levels, humidity, temperature, or nutrient concentrations, and operates the actuators accordingly. It connects to WiFi automatically, either using saved credentials or by allowing the user to configure the WiFi via an access point (AP).</p>

<h2>Features</h2>
<ul>
    <li>Connects to a WiFi network using <strong>WiFiManager</strong>. If no network is configured, it creates an access point for manual configuration.</li>
    <li>Communicates with the <strong>ThingSpeak</strong> cloud platform to retrieve sensor readings and update actuator states.</li>
    <li>Reads values from multiple ThingSpeak channel fields and controls actuators based on the data:</li>
    <ul>
        <li>Field 5: Controls PWM output on GPIO 5 (analog output).</li>
        <li>Field 6: Controls PWM output on GPIO 4 (analog output).</li>
        <li>Field 7: Controls PWM output on GPIO 0 (analog output).</li>
        <li>Field 8: Controls digital output on GPIO D7 or D8 (actuator triggering).</li>
    </ul>
    <li>If the actuator is triggered (based on Field 8), the status is updated back to ThingSpeak for tracking.</li>
    <li>Automatically restarts and attempts reconnection to the WiFi network in case of failure.</li>
</ul>

<h2>Hardware Used</h2>
<ul>
    <li><strong>Wemos D1 Mini</strong> as the microcontroller (based on ESP8266).</li>
    <li><strong>L293D Motor Drivers</strong> for controlling motors and actuators.</li>
    <li><strong>Opto Isolators</strong> for ensuring electrical isolation between the control signals and high-power components.</li>
</ul>

<h2>Libraries Used</h2>

<h3>WiFiManager Library</h3>
<p><strong>WiFiManager</strong> is used to simplify the process of connecting the ESP8266 to a WiFi network. With this library, the device automatically connects to the last known WiFi network. If the device is unable to connect (e.g., incorrect credentials or network change), it will set up an access point, allowing you to configure the WiFi network manually through a web portal.</p>

<h4>Key Features of WiFiManager:</h4>
<ul>
    <li>Automatically connects to saved WiFi credentials or provides an access point for manual configuration.</li>
    <li>Eliminates the need to hardcode WiFi credentials into the program, allowing easy updates.</li>
    <li>If a connection fails, the system restarts and attempts to connect again, ensuring reliability.</li>
    <li>Supports setting custom SSID and password for the access point, enhancing security.</li>
</ul>

<h3>ThingSpeak Library</h3>
<p><strong>ThingSpeak</strong> is an open IoT platform that allows easy data communication between devices and the cloud. In this project, the ThingSpeak library is used to read data from specific fields of a ThingSpeak channel and control actuators accordingly. The actuators could be various devices like water pumps, lights, fans, etc., depending on the requirements of the hydroponic farming system.</p>

<h4>Key Features of ThingSpeak Library:</h4>
<ul>
    <li>Enables ESP8266 to read data from multiple fields of a ThingSpeak channel (e.g., sensor readings).</li>
    <li>Allows writing data back to the ThingSpeak channel to log actuator status or update fields.</li>
    <li>Uses a WiFi client for seamless communication with the cloud.</li>
    <li>Provides simple APIs for reading and writing long integer values (used for actuator control in this project).</li>
</ul>

</body>
</html>
