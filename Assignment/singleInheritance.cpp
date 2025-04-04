
#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    void getPersonDetails() {
        cout << "Enter name: ";
        
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
    }

    void showPersonDetails() {
        cout << "Name: " << name << "\nAge: " << age << endl;
    }
};

class Student : public Person {
private:
    int rollNumber;

public:
    void getStudentDetails() {
        getPersonDetails();
        cout << "Enter roll number: ";
        cin >> rollNumber;
    }

    void showStudentDetails() {
        cout << "\n===== Student Details =====\n";
        showPersonDetails();
        cout << "Roll Number: " << rollNumber << endl;
    }
};

int main() {
    Student s;
    cout << "Enter student details:\n";
    
    s.getStudentDetails();    
    s.showStudentDetails();
    s.showPersonDetails();
    return 0;
}
