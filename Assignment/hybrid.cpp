#include <iostream>
using namespace std;

// Base class Animal
class Animal {
public:
    Animal(string n) : name(n) {}
    void speak() {
        cout << name << " makes a sound" << endl;
    }
    string name;
};

// Base class Bird 
class Bird {
public:
    Bird(string c) : color(c) {}
    void fly() {
        cout << "The " << color << " bird is flying" << endl;
    }
    string color;
};

// Base class Mammal 
class Mammal : public Animal {
public:
    Mammal(string n) : Animal(n) {}
    void walk() {
        cout << "The mammal is walking" << endl;
    }
};

// Derived class Bat
class Bat : public Mammal, public Bird {
public:
    Bat(string n, string c) : Mammal(n), Bird(c) {}

    void displayInfo() {
        cout << "This is a Bat named " << name << " and it is " << color << " in color." << endl;
    }
};

int main() {
    // Create an object of Bat (Hybrid inheritance)
    Bat bat("Bat", "black");

    bat.speak();        // From Animal (via Mammal)
    bat.fly();          // From Bird
    bat.walk();         // From Mammal
    bat.displayInfo();  // From Bat class

    return 0;
}

