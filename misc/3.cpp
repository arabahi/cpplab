#include<iostream>
using namespace std;

class A {
	int a;
	protected:
		int prot_a;
		void set_prot_a() {
			cout << "Enter prot_a: ";
			cin >> prot_a;
		}
	public:
		void set_a() {
			cout << "Enter a: ";
			cin >> a;
		}
		int get_a() {
			return a;
		}
};

class B: public A {
	int b;
	public:
		void set_b() {
			cout << "Enter b: ";
			cin >> b;
		}
		int get_b() {
			return b;
		}
		int get_prot_a() {
			return prot_a;
		}
		void set_prot() {
			set_prot_a();
		}
};

int main() {
	B b;
	b.set_a();
	b.set_b();
	b.set_prot();
	cout << "a: " << b.get_a() << endl;
	cout << "b: " << b.get_b() << endl;
	cout << "prot_b: " << b.get_prot_a() << endl;
	return 0;
}
