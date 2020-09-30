#include "WebPage.h"

void WebPage::setAddress(const char * address)
{
	if (address == nullptr)
	{
		return;
	}
	delete[] this->address;
	this->address = new char[strlen(address) + 1];
	strcpy_s(this->address, strlen(address) + 1, address);
}

char * WebPage::getAddress() const
{
	return this->address;
}

void WebPage::setIpAddress(const char * IpAddress)
{
	if (IpAddress == nullptr)
	{
		return;
	}
	delete[] this->IpAddress;
	this->IpAddress = new char[strlen(IpAddress) + 1];
	strcpy_s(this->IpAddress, strlen(IpAddress) + 1, IpAddress);
}

char * WebPage::getIpAddress() const
{
	return this->IpAddress;
}

WebPage::WebPage()
{
	setAddress("def address");
	setIpAddress("123.45.67");
}

WebPage::WebPage(const WebPage & wp)
{
	setAddress(wp.getAddress());
	setIpAddress(wp.getIpAddress());
}

WebPage & WebPage::operator=(const WebPage & wp)
{
	if (this != &wp)
	{
		setAddress(wp.getAddress());
		setIpAddress(wp.getIpAddress());
	}
	return *this;
}

WebPage::~WebPage()
{
	delete[] this->address;
	delete[] this->IpAddress;
}

ostream & operator<<(ostream & os, const WebPage & wp)
{
	os << "Address: " << wp.getAddress() << endl;
	os << "IpAddress: " << wp.getIpAddress() << endl;

	return os;
}

istream & operator>>(istream & is, WebPage & wp)
{
	char strInput[150];
	is >> strInput;
	wp.setAddress(strInput);

	is >> strInput;
	wp.setIpAddress(strInput);

	return is;
}