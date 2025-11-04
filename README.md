

🏠 IoT-Based Home Automation using Smartphone and ESP32

📖 Overview

This project demonstrates how to control home appliances using a smartphone and an ESP32 microcontroller through Wi-Fi.
It allows you to switch ON/OFF appliances like fans, lights, or other devices using the Blynk IoT App or a web interface.


---

🎯 Objectives

Control electrical appliances remotely via smartphone.

Learn about IoT concepts like Wi-Fi, MQTT, and cloud connectivity.

Implement automation using ESP32 and relay modules.



---

🧩 Components Used

Component	Description

ESP32	Wi-Fi enabled microcontroller
Relay Module	Controls AC appliances
Jumper Wires	For circuit connections
Breadboard	For easy wiring
Smartphone	To control appliances
Power Source	5V USB or adapter



---

⚙️ Working Principle

1. The ESP32 connects to a Wi-Fi network.


2. The Blynk app (or local web server) sends commands to ESP32.


3. ESP32 receives the signal and activates the relay module.


4. The relay acts as a switch for the home appliance (ON/OFF).




---

🔌 Circuit Diagram

Smartphone → Wi-Fi Router → ESP32 → Relay Module → Appliance

ESP32 Pin	Relay Pin	Function

D23	IN1	Control Signal
5V	VCC	Power
GND	GND	Ground

![relay-esp32-wiring](https://github.com/user-attachments/assets/24542ce2-d776-42f0-a552-951b33289ea3)


🧠 Code (Using Blynk IoT App)

Filename: home_automation_blynk.ino

#define BLYNK_TEMPLATE_ID "Your_Template_ID"
#define BLYNK_AUTH_TOKEN "Your_Auth_Token"
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "Your_Auth_Token";
char ssid[] = "Your_WiFi_Name";
char pass[] = "Your_WiFi_Password";

int relayPin = 23;

void setup() {
  Serial.begin(115200);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);
  Blynk.begin(auth, ssid, pass);
}

BLYNK_WRITE(V1) {
  int value = param.asInt();
  digitalWrite(relayPin, value);
}

void loop() {
  Blynk.run();
}



---

📱 Blynk Setup Steps

1. Download Blynk IoT App (Android/iOS).


2. Create a new project → Select ESP32 and Wi-Fi.


3. Add a Button widget linked to Virtual Pin V1.


4. Copy the Auth Token and paste it in your Arduino code.


5. Upload the code to ESP32 and control from app.




---

📸 Demo

Action: Control bulb ON/OFF from smartphone.

Result: Relay clicks → Appliance responds instantly.


(You can attach your project images or video demo here.)


---

📊 Future Improvements

Add voice control (Google Assistant / Alexa).

Use sensors (temperature, motion) for automation.

Add data logging and cloud monitoring.



Feel free to use and modify for learning and research purposes
