#pragma once
#include <iostream>

using namespace std;

class BankAccount
{
private:
	int balance;
	int limit;

public:
	void setBalance(const int balance);
	const int getBalance() const;
	void setLimit(const int limit);
	const int getLimit() const;

	BankAccount();
	BankAccount(const int balance, const int limit);

	void pay(const int sum);

	void addMoney(const int sum);

	void withdrawMoney(const int sum);

	void print() const;
};