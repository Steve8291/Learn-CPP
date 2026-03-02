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
    Serial.println();
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
    Serial.println(" mph!\n");
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

    sayHello("Alice");

    describePet("cat", "Fluffy");
    describePet("Harry", "Hamster"); // Oops, we switched the order of the arguments! This is why positional arguments can be tricky.

    describeCar("Model S", "Tesla", 150);
    describeCar("Civic", "Honda"); // This will use the default speed of 100 mph

    String full_name = getFormattedName("John", "Doe");
    Serial.println(full_name);

    int sum = addNumbers(5, 7);
    Serial.print("5 + 7 = ");
    Serial.println(sum);

    Serial.println(addNumbers(10, 20)); // We can also print the result of a function directly without storing it in a variable first

}



void loop() {
    // Empty
}