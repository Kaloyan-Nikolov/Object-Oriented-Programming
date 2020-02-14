#pragma once
#include <iostream>

class Guest
{
private:
	char* IPaddress = nullptr;

protected:
	void setIPaddress(const char* IPaddress);
public:
	const char* getIPaddress() const;

	Guest();
	Guest(const char* IPaddress);
	Guest(const Guest &g);
	Guest& operator=(const Guest &g);
	virtual ~Guest();

	virtual void printDetails() const;
};
