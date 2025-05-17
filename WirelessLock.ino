#define BLYNK_TEMPLATE_ID "TMPLxxxxxxx"       // Replace with your real Template ID
#define BLYNK_TEMPLATE_NAME "Room Lock"       // Or your actual template name
#define BLYNK_AUTH_TOKEN "your_auth_token"    // From your device info

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// Your WiFi credentials
char ssid[] = "Wifi_Name";  //2.4 GHz Wifi will be used, if you bought a new Official ESP32, 5Ghz can also work.The code wil work for unofficial esp32 also  
char pass[] = "Password"; 

#define SOLENOID_PIN 26  // GPIO pin connected to the relay's IN pin

BLYNK_WRITE(V1) {
  int value = param.asInt();
  Serial.print("Received value: ");
  Serial.println(value);

  if (value == 1) {
    digitalWrite(SOLENOID_PIN, HIGH);  // Unlock
    Serial.println("Unlocking...");
  } else {
    digitalWrite(SOLENOID_PIN, LOW);   // Lock
    Serial.println("Locking...");
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(SOLENOID_PIN, OUTPUT);
  digitalWrite(SOLENOID_PIN, LOW);  // Start locked
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();  
}
