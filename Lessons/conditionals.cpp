# include <Arduino.h>

int a, b, c, x; // Declare variables

void setup() {
    Serial.begin(115200);
    delay(1000); // Give the serial monitor time to connect


    // ________ If Statement ________
    Serial.println("________ If Statement ________");
    a = 33;
    b = 200;
    if (b > a) {
        Serial.println("b is greater than a");
    }

    // ________ Else If Statement ________
    Serial.println("\n________ Else If Statement ________");
    a = 33;
    b = 33;
    if (b > a) {
        Serial.println("b is greater than a");
    } else if (a == b) {
        Serial.println("a and b are equal");
    }

    // ________ Else Statement ________
    Serial.println("\n________ Else Statement ________");
    a = 200;
    b = 33;
    if (b > a) {
        Serial.println("b is greater than a");
    } else if (a == b) {
        Serial.println("a and b are equal");
    } else {
        Serial.println("a is greater than b");
    }

    // ________ And Statement ________
    Serial.println("\n________ And Statement ________");
    a = 200;
    b = 33;
    c = 500;
    if (a > b && c > a) {
        Serial.println("Both conditions are True");
    }

    // ________ Or Statement ________
    Serial.println("\n________ Or Statement ________");
    a = 200;
    b = 33;
    c = 500;
    if (a > b || a > c) {
        Serial.println("At least one of the conditions is True");
    }

    // ________ Not Statement ________
    Serial.println("\n________ Not Statement ________");
    a = 33;
    b = 200;
    if (!(a > b)) {
        Serial.println("a is NOT greater than b");
    }

    // ________ Nested If Statement ________
    Serial.println("\n________ Nested If Statement ________");
    x = 41;
    if (x > 10) {
        Serial.println("Above ten,");
        if (x > 20) {
        Serial.println("and also above 20!");
        } else {
        Serial.println("but not above 20.");
        }
    } else {
        Serial.println("Not above 10");
    }
}

void loop() {
  // Empty, as we only wanted to run the logic once.
}


/*
Assignment: Letter Grade Assigner
Write a program that takes a numerical grade (0-100) as input and assigns a letter grade based on the following scale:
90-100: A
80-89: B
70-79: C
60-69: D
0-59: F
The program should also handle invalid input (e.g., numbers outside the 0-100 range) 
and prompt the user to enter a valid grade. Use if-else, else if statements to implement the logic
*/