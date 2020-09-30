#pragma once
#include "Person.h"
#include "BankAccount.h"

class PersonWithAccount : public Person, public BankAccount
{
private:
	char* iban = nullptr;
public:

	void setIban(const char* iban);
	const char* getIban() const;

	PersonWithAccount();
	PersonWithAccount(const char * name, const char * egn, const int age, const int year, const int balance, const int limit, const char * iban);

	PersonWithAccount(const PersonWithAccount &pwa);
	PersonWithAccount& operator=(const PersonWithAccount &pwa);
	~PersonWithAccount();

	void regester();
	void print() const;
};