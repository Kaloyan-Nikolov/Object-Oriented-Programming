#include "PersonWithAccount.h"

void PersonWithAccount::setIban(const char * iban = "1234567890")
{
	bool isCorrect = true;
	if (iban == nullptr || strlen(iban) != 10)
	{
		cout << "Incorrect iban! Deafault was set!" << endl;
		isCorrect = false;
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			if (iban[i] > '9' || iban[i] < '0')
			{
				cout << "Incorrect iban! Deafault was set!" << endl;
				isCorrect = false;
				break;
			}
		}
	}

	if (isCorrect)
	{
		delete[] this->iban;
		this->iban = new char[strlen(iban) + 1];
		strcpy_s(this->iban, strlen(iban) + 1, iban);
	}
	else
	{
		delete[] this->iban;
		this->iban = new char[strlen("1234567890") + 1];
		strcpy_s(this->iban, strlen(iban) + 1, "1234567890");
	}
}

const char * PersonWithAccount::getIban() const
{
	return this->iban;
}

PersonWithAccount::PersonWithAccount()
{
	setIban();
}

PersonWithAccount::PersonWithAccount(const char * name, const char * egn, const int age, const int year, const int balance, const int limit, const char * iban)
	:Person(name, egn, age, year), BankAccount(balance, limit)
{
	setIban(iban);
}

PersonWithAccount::PersonWithAccount(const PersonWithAccount & pwa) :
	Person(pwa.getName(), pwa.getEgn(), pwa.getAge(), pwa.getYear()), BankAccount(pwa.getBalance(), pwa.getLimit())
{
	setIban(pwa.getIban());
}

PersonWithAccount & PersonWithAccount::operator=(const PersonWithAccount & pwa)
{
	if (this != &pwa)
	{
		Person::operator=(pwa);
		BankAccount::operator=(pwa);
		setIban(pwa.getIban());
	}

	return *this;
}

PersonWithAccount::~PersonWithAccount()
{
	delete[] this->iban;
}

void PersonWithAccount::regester()
{
	pay(10);
	cout << "Name: " << getName() << endl;
	cout << "IBAN: " << getIban() << endl;
	cout << "Balance: " << getBalance() << endl;
}

void PersonWithAccount::print() const
{
	Person::print();
	BankAccount::print();
	cout << "IBAN: " << getIban() << endl;
}