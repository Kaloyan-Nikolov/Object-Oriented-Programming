#include "BankAccount.h"

void BankAccount::setBalance(const int balance)
{
	this->balance = balance;
}

const int BankAccount::getBalance() const
{
	return this->balance;
}

void BankAccount::setLimit(const int limit)
{
	this->limit = limit;
}

const int BankAccount::getLimit() const
{
	return this->limit;
}

BankAccount::BankAccount()
{
	setBalance(2000);
	setLimit(1000);
}

BankAccount::BankAccount(const int balance, const int limit)
{
	setBalance(balance);
	setLimit(limit);
}

void BankAccount::pay(const int sum)
{
	int NewBalance = getBalance() - sum;
	int MinusLimit = -getLimit();
	if (NewBalance >= MinusLimit)
	{
		setBalance(NewBalance);
		cout << "After payment, the balance was change to: " << getBalance() << endl;
	}
	else
	{
		cout << "Error! You do not have enough money to pay!" << endl;
	}
}

void BankAccount::addMoney(const int sum)
{
	setBalance(getBalance() + sum);
	cout << "The balance was increased to: " << getBalance() << endl;
}

void BankAccount::withdrawMoney(const int sum)
{
	int NewBalance = getBalance() - sum;
	if (NewBalance >= 0)
	{
		setBalance(NewBalance);
		cout << "The balance was decreased to: " << getBalance() << endl;
	}
	else
	{
		cout << "Error! You do not have enough money to withdraw!" << endl;
	}
}

void BankAccount::print() const
{
	cout << "Balance: " << getBalance() << endl;
	cout << "Limit: " << getLimit() << endl;
}