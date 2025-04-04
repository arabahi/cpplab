#include <iostream>
#include <string>
using namespace std;

// Base class 
class Vehicle {
public:
    string brand;
    int year;

    Vehicle(string b, int y) : brand(b), year(y) {}

    void displayInfo() {
        cout << "Vehicle Brand: " << brand << ", Year: " << year << endl;
    }
};

// Derived class 
class Car : public Vehicle {
public:
    int doors;

    Car(string b, int y, int d) : Vehicle(b, y), doors(d) {}

    void displayCarInfo() {
        cout << "This car has " << doors << " doors." << endl;
    }
};

// Further derived class 
class ElectricCar : public Car {
public:
    int batteryCapacity;

    ElectricCar(string b, int y, int d, int bc) : Car(b, y, d), batteryCapacity(bc) {}

    void displayElectricCarInfo() {
        cout << "This electric car has a battery capacity of " << batteryCapacity << " kWh." << endl;
    }
};

int main() {

    ElectricCar eCar("Tesla", 2023, 4, 75);


    eCar.displayInfo();  // From Vehicle class
    eCar.displayCarInfo();  // From Car class
    eCar.displayElectricCarInfo();  // From ElectricCar class

    return 0;
}
//output
//Vehicle Brand: Tesla, Year: 2023
//This car has 4 doors.
//This electric car has a battery capacity of 75 kWh.


