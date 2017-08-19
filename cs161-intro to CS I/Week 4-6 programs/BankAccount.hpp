/*********************************************************************
** Author: Ethan Dunham
** Date: 10/22/16
** Description: This header file is for the BankAccount class.
***********************************************************************/

#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP
#include <string>
using std::string;

class BankAccount
{
	private:
		string customerName;
		string customerID;
		double customerBalance;

	public:
		BankAccount(string, string, double);
		BankAccount();
		string getCustomerName();
		string getCustomerID();
		double getCustomerBalance();
		void withdraw(double);
		void deposit(double);
};
#endif