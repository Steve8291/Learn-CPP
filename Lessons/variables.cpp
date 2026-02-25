/*
 * ESP32 Variable Demonstration
 * Set these in your platforio.ini
    * monitor_speed = 115200
    * monitor_filters = send_on_enter
    * monitor_echo = yes
 */

#include <Arduino.h>

// Global Variables
int userAge;           // Integers: whole numbers like 0, 1, -5, 42, etc.
float userHeight;      // Decimal numbers: 3.14, 1.82, etc.
char userInitial;      // Single character: 'A', '@', '3', etc.
bool isProgramRunning; // true/false
String userName;       // Dynamic string object: "Hello World", "ESP32", etc.


void clearBuffer() {
    while(Serial.available() > 0) Serial.read(); 
}

void printSummary() {
    Serial.println("\n--- Data Summary ---");
    Serial.print("User: ");
    Serial.print(userName);
    Serial.print(" ");
    Serial.println(userInitial);
    Serial.printf("Age: %d years\n", userAge);
    Serial.printf("Height: %.2f meters\n", userHeight);
  
    if (isProgramRunning) {
        Serial.println("Status: ESP32 logic active.");
    }
    
    Serial.println("\nRestarting in 10 seconds...");
    delay(10000);
    ESP.restart(); // Unique ESP32 command to reboot the chip
}

void setup() {
    // ESP32 standard baud rate is 115200
    Serial.begin(115200); 
    delay(1000); // Give the serial monitor time to connect
    clearBuffer();

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

/*
Assignment: Write a program to calculate how old a dog is in "dog years".

Dogs mature at a faster rate than human beings. 
If you own a dog, you might’ve heard this rule: one year for Snoopy equals seven years for you. 
Turns out, the math isn’t that simple. Dogs mature more quickly than we do early on.

Here’s how we can convert your dog’s age into human years:

   * The first two years of a dog’s life count as 21 human years.
   * Each following year counts as 4 human years.

So a one-year-old dog is 10.5 years old in human years, and a two-year-old dog is 21 years old in human years… 

Write a C++ program called dog_years.cpp to calculate the age, in human years, of any dog older than 2.
*/