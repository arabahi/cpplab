#include<iostream>
#include<math.h>
using namespace std;
class bank{
	float bal;
	float roi;
	public:
	bank(float bal,float roi){
		this->bal = bal;
		this->roi = roi;
	}
	~bank(){}
	void deposit(int val){
		bal+=val;
	}
	void withdraw(int val){
		if(val<=bal){
			bal -= val;
		}
		else{
			cout<<"Insufficient balance"<<endl;
		}
	}
	void ci(int time){
		bal = bal * pow((1+roi/100),time);
	}
	void balance(){
		cout<<"Balance : "<<bal<<endl;
	}
};
int main(){
	float bal,roi;
	cout<<"Enter balance and Rate of Interest : ";
	cin>>bal>>roi;
	bank acc1(bal,roi);
	while(true){
		cout<<"Banking System"<<endl;
		cout<<"1.Deposit"<<endl;
		cout<<"2.Withdraw"<<endl;
		cout<<"3.Compound Interest"<<endl;
		cout<<"4.Balance"<<endl;
		cout<<"5.Exit"<<endl;
		int choice;
		cin>>choice;
		switch(choice){
			int val,time;
			case 1: 
			cin>>val;
			acc1.deposit(val);
			break;
			
			case 2:
			cin>>val;
			acc1.withdraw(val);
			break;
			
			case 3:
			cin>>time;
			acc1.ci(time);
			break;
			
			case 4:
			acc1.balance();
			break;
			
			case 5:
			return 0;
		}
	}
	return 0;
}
