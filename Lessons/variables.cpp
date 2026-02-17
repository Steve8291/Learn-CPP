/*
 * ESP32 Variable Demonstration
 * Set these in your platforio.ini
    * monitor_speed = 115200
    * monitor_filters = send_on_enter
    * monitor_echo = yes
 */

#include <Arduino.h>

// Global Variables
int userAge;           // 32-bit on ESP32 (-2,147,483,648 to 2,147,483,647)
float userHeight;      // 32-bit decimal
char userInitial;      // Single character
bool isProgramRunning; // true/false
String userName;       // Dynamic string object


void clearBuffer() {
    while(Serial.available() > 0) Serial.read(); 
}

void printSummary() {
    Serial.println("\n--- Data Summary ---");
    Serial.printf("User: %s (%c)\n", userName.c_str(), userInitial);
    Serial.printf("Age: %d years\n", userAge);
    Serial.printf("Height: %.2f meters\n", userHeight);
  
    if (isProgramRunning) {
        Serial.println("Status: ESP32 logic active.");
    }
    
    Serial.println("\nRestarting in 5 seconds...");
    delay(5000);
    ESP.restart(); // Unique ESP32 command to reboot the chip
}

void setup() {
    // ESP32 standard baud rate is 115200
    Serial.begin(115200); 
    delay(1000); // Give the serial monitor time to connect

    isProgramRunning = true;

    Serial.println("\n--- ESP32 Variable Demo ---");
    Serial.println("Please enter your First Name:");
}

void loop() {
    // Step 1: Read String
    if (Serial.available() > 0 && userName == "") {
        userName = Serial.readStringUntil('\n');
        userName.trim(); // Remove any trailing whitespace or carriage returns
        Serial.printf("Hello, %s!\n", userName.c_str()); // Using printf (cool ESP32 feature)
        Serial.println("What is your first initial?");
    }

    // Step 2: Read Char
    else if (Serial.available() > 0 && userInitial == '\0' && userName != "") {
        userInitial = Serial.read();
        clearBuffer(); 
        Serial.print("Initial stored as: ");
        Serial.println(userInitial);
        Serial.println("How old are you?");
    }

    // Step 3: Read Int
    else if (Serial.available() > 0 && userAge == 0 && userInitial != '\0') {
        userAge = Serial.parseInt();
        clearBuffer();
        Serial.print("Age stored: ");
        Serial.println(userAge);
        Serial.println("How tall are you in meters? (e.g., 1.82)");
    }

    // Step 4: Read Float
    else if (Serial.available() > 0 && userHeight == 0 && userAge != 0) {
        userHeight = Serial.parseFloat();
        clearBuffer();
        printSummary();
    }
}