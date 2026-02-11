#include <Arduino.h>

void setup() {
  // Initialize the serial communication at 115200 baud rate
  Serial.begin(115200); 
}

void loop() {
  // Print "Hello World!" to the Serial Monitor
  Serial.println("Hello World!");
  Serial.print("Welcome to ");
  Serial.println("My WORLD!!");
  Serial.println("");
  Serial.println("C++ programming on ESP32!");
  Serial.print("Harmony School\nAwesome!\n\n");


  // Wait for 2 seconds before repeating the loop
  delay(2000); 
}