#include<iostream>
#include<string>
#include "BankAccount.hpp"
using namespace std;

int main()
{
	double balance, withdraw, deposit;
	string customerName, customerID;

	cout << "customer name?" << endl;
	cin >> customerName;
	cout << "ID?" << endl;
	cin >> customerID;
	cout << "balance?"<< endl;
	cin >> balance;
	BankAccount account1(customerName, customerID, balance);
	account1.withdraw(244.0);
	account1.withdraw(3012.58);
	account1.deposit(37.54);
	account1.withdraw(1807.12);
	account1.deposit(500.00);
	double finalBalance = account1.getCustomerBalance();
	cout << finalBalance << endl;

}