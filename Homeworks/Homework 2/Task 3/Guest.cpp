#include "Guest.h"

void Guest::setIPaddress(const char * IPaddress)
{
	if (IPaddress == nullptr)
	{
		return;
	}
	delete[] this->IPaddress;
	this->IPaddress = new char[strlen(IPaddress) + 1];
	strcpy_s(this->IPaddress, strlen(IPaddress) + 1, IPaddress);
}

const char * Guest::getIPaddress() const
{
	return this->IPaddress;
}

Guest::Guest()
{
	setIPaddress("123.45.67.890");
}

Guest::Guest(const char * IPaddress)
{
	setIPaddress(IPaddress);
}

Guest::Guest(const Guest & g)
{
	setIPaddress(g.getIPaddress());
}

Guest & Guest::operator=(const Guest & g)
{
	if (this != &g)
	{
		setIPaddress(g.getIPaddress());
	}
	return *this;
}

Guest::~Guest()
{
	delete[] this->IPaddress;
}

void Guest::printDetails() const
{
	std::cout << "IP address: " << getIPaddress() << std::endl;
}
