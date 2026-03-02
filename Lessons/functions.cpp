/*
 * Arduino Functions Example
 * Note: C++ requires us to define the "type" of data (String, int, etc.)
 */

#include <Arduino.h>

// 1. Simple function
void greetUser() {
    Serial.println("Hello!");
}

// 2. Passing information (Parameters)
void sayHello(String userName) {
    Serial.print("Hello, ");
    Serial.println(userName);
}

// 3. Positional Arguments
void describePet(String animalType, String petName) {
    Serial.print("I have a ");
    Serial.println(animalType);
    Serial.print("My ");
    Serial.print(animalType);
    Serial.print("'s name is ");
    Serial.println(petName);
}

// 4. Default Values
void describeCar(String model, String manufacturer, int speed = 100) {
    Serial.print("I have a ");
    Serial.print(manufacturer);
    Serial.print(" ");
    Serial.println(model);
    Serial.print("My ");
    Serial.print(model);
    Serial.print(" goes ");
    Serial.print(speed);
    Serial.println(" mph!");
}

// 5. Return Values
String getFormattedName(String firstName, String lastName) {
    String fullName = firstName + " " + lastName;
    return fullName;
}

// 6. Returning an int
int addNumbers(int a, int b) {
    return a + b;
}

void setup() {
    Serial.begin(115200);
    delay(1000);
    Serial.println("\n\n");

    // --- Calling the functions ---
    
    greetUser();

    sayHello("bobby bubbles");

    Serial.println("\n________ Positional Parameters ________");
    describePet("cat", "max");

    Serial.println("\n________ Order Matters ________");
    describePet("hamster", "harry");

    Serial.println("\n________ Default Values ________");
    describeCar("Prius", "Toyota");     // Uses default 100
    describeCar("Bug", "VW", 60);      // Overwrites default with 60

    Serial.println("\n________ Return Values ________");
    String musician = getFormattedName("katy", "perry");
    Serial.println(musician);

    Serial.println("\n_________ Return an int ________");
    int sum = addNumbers(5, 7);
    Serial.print("5 + 7 = ");
    Serial.println(sum);
}

void loop() {
    // Leave empty so it doesn't repeat the prints forever
}

/* Assignment: Traffic Light
Build a traffic light controller using functions. 
The traffic light should cycle through green, yellow, and red lights with appropriate delays. 
Use functions to represent each light state and the transitions between them. For example:
    void greenLight() {
        // Code to turn on green light
        delay(5000); // Green light for 5 seconds
    }
*/