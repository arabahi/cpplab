#include<iostream>
using namespace std;

class GrandParent {
	private:
		string name;
	protected:
		string getName() {
			return name;
		}
		void showName() {
			cout << "My name is " << name << endl;
		}
		void setName() {
			cout << "Enter name: ";
			cin >> name;
		}
};

class Parent1 : virtual public GrandParent {
	private:
		int age;
	protected:
		void showAge() {
			cout << "My age is " << age << endl;
		}
		int getAge() {
			return age;
		}
		void setAge() {
			cout << "Enter age: ";
			cin >> age;
		}
};

class Parent2 : virtual public GrandParent {
	private:
		long long phoneNo;
	protected:
		void setPhoneNo() {
			cout << "Enter phone no.: ";
			cin >> phoneNo;
		}
		void showPhoneNo() {
			cout << "My phone no. is " << phoneNo << endl;
		}
		long long getPhoneNo() {
			return phoneNo;
		}
};

class Child : public Parent1, public Parent2 {
	private:
		int gender;
	public:
		void setInfo() {
			setName();
			setAge();
			setPhoneNo();
		}
		void getInfo() {
			showName();
			showAge();
			showPhoneNo();
		}
};

int main() {
	Child c;
	c.setInfo();
	c.getInfo();
	return 0;
}		
