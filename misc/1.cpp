#include<iostream>
#define maxsize 5
using namespace std;

class Queue {
	int first, last, curSize;
	int arr[maxsize];
	public:
		Queue() {
			first = 0;
			last = 0;
			curSize = 0;
		}
		int front() {
			if (isEmpty()) {
				cout << "Queue is empty." << endl;
				return -1;
			}
			return arr[first];
		}
		void pop() {
			if (isEmpty()) {
				cout << "Queue is empty." << endl;
				return;
			}
			first = (first+1) % maxsize;
			curSize--;
		}
		void push(int val) {
			if (curSize >= maxsize) {
				cout << "Queue is full." << endl;
				return;
			}
			arr[last] = val;
			last++;
			curSize++;
		}
		bool isEmpty() {
			return curSize == 0;
		}
		int size() {
			return curSize;
		}
};

int main() {
	Queue q;
	
	bool flag = true;
	
	while (flag) {
		cout << "=======================================" << endl;
		cout << "Choose an operation:\n" << endl;
		cout << "1. Push" << endl;
		cout << "2. Pop" << endl;
		cout << "3. Front" << endl;
		cout << "4. Size" << endl;
		cout << "5. IsEmpty" << endl;
		cout << ">> ";
		int choice, val, size;
		bool empty;
		cin >> choice;
		switch(choice) {
			case 1:
				cout << "Enter val: ";
				cin >> val;
				q.push(val);
				break;
			case 2:
				q.pop();
				break;
			case 3:
				val = q.front();
				if (val > 0) cout << "Front val is " << val << endl;
				break;
			case 4:
				size = q.size();
				cout << "Queue size is " << size << endl;
				break;
			case 5:
				empty = q.isEmpty();
				if (empty) {
					cout << "Queue is empty." << endl;
				} else {
					cout << "Queue is not empty." << endl;
				}
				break;
			default:
				flag = false;
				break;
		}
	}
	return 0;
}
