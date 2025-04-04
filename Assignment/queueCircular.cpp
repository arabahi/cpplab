#include <bits/stdc++.h>
#define MAX_SIZE 50

using namespace std;

class Queue {
public:
    int front, rear;
    int arr[MAX_SIZE];


    Queue() { front = rear = 0; }

    bool isEmpty()
    {
        if (front == rear)
            return true;
        return false;
    }

    bool isFull()
    {
        if ((rear + 1) % MAX_SIZE == front)
            return true;
        return false;
    }

    void enqueue(int val)
    {
        if (this->isFull()) {
            printf("Queue Overflow!\n");
            return;
        }
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = val;
    }

    void dequeue()
    {
        if (this->isEmpty()) {
            printf("Queue Underflow!\n");
            return;
        }
        front = (front + 1) % MAX_SIZE;
    }

    int peek()
    {
        if (this->isEmpty()) {
            printf("Queue is Empty!\n");
            return -1;
        }
        return arr[(front + 1) % MAX_SIZE];
    }

    void print()
    {
        if (this->isEmpty())
            return;
        for (int i = (front + 1) % MAX_SIZE; i < rear;
             i = (i + 1) % MAX_SIZE) {

            printf("%d ", arr[i]);
        }
        cout << arr[rear];
    }
};

int main()
{
    Queue q;
    int choice;
	while(true){
		cout<<"1. Enqueue\n2. Dequeue\n3. print\n4. Peek\n5. isEmpty\n6. Exit"<<endl;
		cin>>choice;
		switch(choice){
			case 1:
				cin>>val;
				q.enqueue(val);
				break;
			case 2:
				q.dequeue();
				break;
			case 3:
				q.print();
				break;
			case 4:
				cout<<"Peek element is "<<q.peek();
				break;
			case 5:
				if(q.isEmpty())
					cout<<"Queue is Empty"<<endl;
				else
					cout<<"Queue is not Empty"<<endl;
				break;
			case 6: 
				return 0;
		}
	}
    return 0;
}
