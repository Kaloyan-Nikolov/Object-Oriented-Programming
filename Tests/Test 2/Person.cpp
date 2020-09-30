#include "Person.h"

void Person::setName(const char * name)
{
	if (name == nullptr)
	{
		return;
	}
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

const char * Person::getName() const
{
	return this->name;
}

void Person::setEgn(const char * egn)
{
	if (egn == nullptr)
	{
		return;
	}
	delete[] this->egn;
	this->egn = new char[strlen(egn) + 1];
	strcpy_s(this->egn, strlen(egn) + 1, egn);
}

const char * Person::getEgn() const
{
	return this->egn;
}

void Person::setAge(const int age)
{
	this->age = age;
}

const int Person::getAge() const
{
	return this->age;
}

void Person::setYear(const int year)
{
	this->year = year;
}

const int Person::getYear() const
{
	return this->year;
}

Person::Person()
{
	setName("Def name");
	setEgn("99123456789");
	setAge(20);
	setYear(1999);
}

Person::Person(const char * name, const char * egn, const int age, const int year)
{
	setName(name);
	setEgn(egn);
	setAge(age);
	setYear(year);
}

Person::Person(const Person & p)
{
	setName(p.getName());
	setEgn(p.getEgn());
	setAge(p.getAge());
	setYear(p.getYear());
}

Person & Person::operator=(const Person & p)
{
	if (this != &p)
	{
		setName(p.getName());
		setEgn(p.getEgn());
		setAge(p.getAge());
		setYear(p.getYear());
	}
	return *this;
}

Person::~Person()
{
	delete[] this->name;
	delete[] this->egn;
}

void Person::print() const
{
	cout << "Name: " << getName() << endl;
	cout << "Egn: " << getEgn() << endl;
	cout << "Age: " << getAge() << endl;
	cout << "Year: " << getYear() << endl;
}