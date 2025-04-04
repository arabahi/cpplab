#include<iostream>
#include<math.h>
using namespace std;

class Account {
	int balance;
	float rate;
	public:
		Account(int bal, float r) {
			balance = bal;
			rate = r;
		}
		void deposit(int amount) {
			balance += amount;
			cout << "Deposited " << amount << "." << endl;
		}
		void withdraw(int amount) {
			if (balance < amount) {
				cout << "Balance not enough." << endl;
				return;
			}
			balance -= amount;
			cout << "Withdrawn " << amount << "." << endl;
		}
		float calculateCI(int t) {
			float p = balance;
			float r = rate;
			float ci = p * pow(1 + r/100, t);
			return ci;
		}
		int getBalance() {
			return balance;
		}
		void displayMenu() {
			cout << "Enter choice:" << endl;
			cout << "1. Deposit" << endl;
			cout << "2. Withdraw" << endl;
			cout << "3. Get Balance" << endl;
			cout << "4. Get CI" << endl;
			cout << "5. Destroy Account" << endl;
		}
		~Account() {
			cout << "Account Destroyed!" << endl;
		}
};

int main() {
	int balance;
	float rate;
	cout << "Enter balance and rate of interest: ";
	cin >> balance >> rate;
	Account *acc = new Account(balance, rate);
	bool flag = true;
	while (flag) {
		int choice, amount, time;
		acc->displayMenu();
		cin >> choice;
		switch(choice) {
			case 1:
				cout << "Enter amount: ";
				cin >> amount;
				acc->deposit(amount);
				break;
			case 2:
				cout << "Enter amount: ";
				cin >> amount;
				acc->withdraw(amount);
				break;
			case 3:
				cout << "Balance : " << acc->getBalance() << endl;
				break;
			case 4:
				cout << "Enter time: ";
				cin >> time;
				cout << "Compound Interest : " << acc->calculateCI(time) << endl;
				break;
			case 5:
				flag = false;
				delete acc;
				break;
			default:
				cout << "Invalid." << endl;
				break;
		}
	}
	return 0;
}
