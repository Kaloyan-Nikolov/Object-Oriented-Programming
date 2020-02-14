#include "DNScache.h"

const int EMPTY_DNSCACHE = -1;

void DNSCache::increaseTop()
{
	top++;
}

void DNSCache::setTop(int top)
{
	if (top >= EMPTY_DNSCACHE)
	{
		this->top = top;
	}
}

int DNSCache::getTop() const
{
	return this->top;
}

void DNSCache::setCapacity(int capacity)
{
	if (capacity > 0)
	{
		this->capacity = capacity;
	}
}

int DNSCache::getCapacity() const
{
	return this->capacity;
}


bool DNSCache::isEmpty() const
{
	return (getTop() == EMPTY_DNSCACHE);
}

bool DNSCache::isFull() const
{
	return (getTop() == getCapacity() - 1);
}

void DNSCache::resize()
{
	int NewCapacity = getCapacity() * 2;
	DNSRecord* newArr = new DNSRecord[NewCapacity];
	for (int i = 0; i < getCapacity(); i++)
	{
		newArr[i] = arr[i];
	}
	delete[] arr;
	arr = newArr;
	setCapacity(NewCapacity);	
}

void DNSCache::copy(const DNSCache &a)
{
	setTop(a.getTop());
	setCapacity(a.getCapacity());	
	arr = new DNSRecord[getCapacity()];

	for(int i = 0; i <= top; i++)
	{
		arr[i] = a.arr[i];
	}
}

DNSCache::DNSCache()
{
	setTop(EMPTY_DNSCACHE);
	setCapacity(1);	
	this->arr = new DNSRecord[getCapacity()];	
}

DNSCache::DNSCache(const DNSCache & a)
{
	copy(a);
}

DNSCache & DNSCache::operator=(const DNSCache & a)
{
	if (this != &a)
	{
		delete[] this->arr;
		copy(a);
	}
	
	return *this;
}

void DNSCache::add(const DNSRecord & a)
{
	if (isFull())
	{
		resize();
	}

	increaseTop();
	arr[getTop()] = a;
}

char * DNSCache::lookup(const char * domainNameOfDNSRecord) const
{
	if (isEmpty())
	{
		std::cout << "Error! The DNSCache is empty." << std::endl;
		return nullptr;
	}

	for (int i = 0; i <= getTop(); i++)
	{
		if (strcmp(domainNameOfDNSRecord, arr[i].getDomainName()) == 0)
		{
			return arr[i].getIpAddress();
		}
	}

	std::cout << "Error! There is not a DNSRecord with this name." << std::endl;
	return nullptr;
}

void DNSCache::flush()
{
	delete[] this->arr;
	arr = new DNSRecord[capacity];
	setTop(EMPTY_DNSCACHE);
}

void DNSCache::print() const
{
	if (isEmpty())
	{
		std::cout << "Error! The DNSCache is empty." << std::endl;
		return;
	}

	for (int i = 0; i <= top; i++)
	{
		std::cout << "DNSRecord #" << i + 1 << " is: " << std::endl;
		arr[i].print();
	}
}

DNSCache::~DNSCache()
{
	delete[] arr;
}
