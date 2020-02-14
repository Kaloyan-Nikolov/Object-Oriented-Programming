#pragma once
#include "DNSRecord.h"

class DNSCache 
{
private:
	DNSRecord* arr;
	int top; // index of last element
	int capacity; // maximum number of elements

	void increaseTop();
	void setTop(int top);
	int getTop() const;

	void setCapacity(int capacity);
	int getCapacity() const;

	bool isEmpty() const;
	bool isFull() const;
	void resize();

	void copy(const DNSCache &a); // the code used in both copy constructor and operator=

public:
	DNSCache();		
	DNSCache(const DNSCache &a);
	DNSCache& operator=(const DNSCache &a);

	void add(const DNSRecord &a);
	char* lookup(const char* domainNameOfDNSRecord) const;
	void flush();
	void print() const;

	~DNSCache();
};
