#pragma once
#include <iostream>

class DNSRecord
{
private:
	char* domainName = nullptr;
	char* ipAddress = nullptr;

	void copy(const DNSRecord &a);

public:
	void setDomainName(const char* domainName);
	char* getDomainName() const;

	void setIpAddress(const char* ipAddress);
	char* getIpAddress() const;

	DNSRecord();
	DNSRecord(const char* domainName, const char* ipAddress);
	DNSRecord(const DNSRecord &a);
	DNSRecord& operator=(const DNSRecord &a);
	~DNSRecord();

	void print() const;	
};
