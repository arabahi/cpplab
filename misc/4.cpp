#include<iostream>
using namespace std;

class Thing {
	string name;
	protected:
		void set_name() {
			cout << "Enter name: ";
			cin >> name;
		}
		void get_name() {
			cout << "Name: " << name << endl;
		}
};

class Animal: public Thing {
	string animal_type;
	protected:
		void set_animal_type() {
			cout << "Enter Animal type: ";
			cin >> animal_type;
		}
		void get_animal_type() {
			cout << "Animal Type: " << animal_type << endl;
		}
};
		
class Dog: public Animal {
	string breed;
	protected:
		void set_breed() {
			cout << "Enter breed: ";
			cin >> breed;
		}
		void get_breed() {
			cout << "Breed: " << breed << endl;
		}
	public:
		void set_info() {
			set_name();
			set_animal_type();
			set_breed();
		}
		void get_info() {
			get_name();
			get_animal_type();
			get_breed();
		}
};

int main() {
	Dog myDog;
	myDog.set_info();
	cout << endl;
	myDog.get_info();
}
