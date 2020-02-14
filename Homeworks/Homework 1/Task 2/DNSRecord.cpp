#include "DNSRecord.h"

void DNSRecord::copy(const DNSRecord & a)
{
	setDomainName(a.getDomainName());
	setIpAddress(a.getIpAddress());
}

// setters and getters

void DNSRecord::setDomainName(const char * domainName)
{
	if (domainName == nullptr)
	{
		return;
	}

	delete[] this->domainName;
	int sizeDomain = strlen(domainName) + 1;
	this->domainName = new char[sizeDomain];
	strcpy_s(this->domainName, sizeDomain, domainName);

}

char * DNSRecord::getDomainName() const
{
	return this->domainName;
}

void DNSRecord::setIpAddress(const char * ipAddress)
{
	if (ipAddress == nullptr)
	{
		return;
	}

	delete[] this->ipAddress;
	int sizeIpAddress = strlen(ipAddress) + 1;
	this->ipAddress = new char[sizeIpAddress];
	strcpy_s(this->ipAddress, sizeIpAddress, ipAddress);
}

char * DNSRecord::getIpAddress() const
{
	return this->ipAddress;
}

// constructors

DNSRecord::DNSRecord()
{
	setDomainName("Default name");
	setIpAddress("123.456.789.0");	
}

DNSRecord::DNSRecord(const char * domainName, const char * ipAddress)
{
	setDomainName(domainName);
	setIpAddress(ipAddress);	
}

DNSRecord::DNSRecord(const DNSRecord & a)
{
	copy(a);
}

DNSRecord & DNSRecord::operator=(const DNSRecord & a)
{
	if (this != &a)	
	{
		
		copy(a);
	}
	
	return *this;
}

void DNSRecord::print() const
{
	std::cout << "domainName: " << getDomainName() << "\t ipAddress: " << getIpAddress() << std::endl;
}

DNSRecord::~DNSRecord()
{
	delete[] domainName;
	delete[] ipAddress;
}
