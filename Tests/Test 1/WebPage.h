#pragma once
#include <iostream>
using namespace std;

class WebPage
{
private:
	char* address = nullptr;
	char* IpAddress = nullptr;

public:
	void setAddress(const char* address);
	char* getAddress() const;
	void setIpAddress(const char* IpAddress);
	char* getIpAddress() const;

	WebPage();
	WebPage(const WebPage& wp);
	WebPage& operator=(const WebPage& wp);
	~WebPage();

	friend ostream& operator<<(ostream& os, const WebPage& wp);
	friend istream& operator>>(istream& is, WebPage& wp);
};
