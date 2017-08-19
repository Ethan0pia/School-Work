/*********************************************************************
** Author: Ethan Dunham
** Date: 10/22/16
** Description: These are the functions for the BankAccount class.
***********************************************************************/

#include "BankAccount.hpp"
#include<iostream>
#include <string>
using std::string;

BankAccount::BankAccount(string name, string ID, double bal)
{
	customerName = name;
	customerID = ID;
	customerBalance = bal;
}

BankAccount::BankAccount()
{
	customerName = "NA";
	customerID = "NA";
	customerBalance = 0.0;
}

string BankAccount::getCustomerName()
{
	return customerName;
}

string BankAccount::getCustomerID()
{
	return customerID;
}

double BankAccount::getCustomerBalance()
{
	return customerBalance;
}

void BankAccount::withdraw(double withdraw)
{
	customerBalance -= withdraw;
}

void BankAccount::deposit(double deposit)
{
	customerBalance += deposit;
}