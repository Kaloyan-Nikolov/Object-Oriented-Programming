#pragma once
#include <iostream>

using namespace std;

class Person
{
private:
	char* name = nullptr;
	char* egn = nullptr;
	int age;
	int year;

public:
	void setName(const char* name);
	const char* getName() const;
	void setEgn(const char* egn);
	const char* getEgn() const;
	void setAge(const int age);
	const int getAge() const;
	void setYear(const int year);
	const int getYear() const;

	Person();
	Person(const char* name, const char* egn, const int age, const int year);
	Person(const Person &p);
	Person& operator=(const Person &p);
	~Person();

	void print() const;
};