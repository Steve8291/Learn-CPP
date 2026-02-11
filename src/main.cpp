#include <Arduino.h>

void setup() {
  // Initialize the serial communication at 115200 baud rate
  Serial.begin(115200); 
}

void loop() {
  // Print "Hello World!" to the Serial Monitor
  Serial.println("Hello World!");
  Serial.println("Welcome to C++ programming on ESP32!");
  Serial.print("Harmony School\n is learning C++ and ESP32 development. ");


  // Wait for one second
  delay(1000); 
}