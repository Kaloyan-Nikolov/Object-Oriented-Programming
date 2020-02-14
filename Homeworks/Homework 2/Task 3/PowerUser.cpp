#include "PowerUser.h"

const int EMPTY_ARR = -1;

void PowerUser::increaseTop()
{
	top++;
}

void PowerUser::setTop(int top)
{
	this->top = top;
}

const int PowerUser::getTop() const
{
	return this->top;
}

void PowerUser::setCapacity(int capacity)
{
	this->capacity = capacity;
}

const int PowerUser::getCapacity() const
{
	return this->capacity;
}

bool PowerUser::isEmpty() const
{
	return (getTop() == EMPTY_ARR);
}

bool PowerUser::isFull() const
{
	return getTop() + 1 == getCapacity();
}

void PowerUser::resize()
{
	int NewCapacity = getCapacity() * 2;
	User* newArr = new User[NewCapacity];
	for (int i = 0; i < getCapacity(); i++)
	{
		newArr[i] = arr[i];
	}
	delete[] arr;
	arr = newArr;
	setCapacity(NewCapacity);
}

void PowerUser::copy(const PowerUser & p)
{
	setTop(p.getTop());
	setCapacity(p.getCapacity());
	arr = new User[getCapacity()];

	for (int i = 0; i <= getTop(); i++)
	{
		arr[i] = p.arr[i];
	}

	setReputation(p.getReputation());
}

void PowerUser::addToArr(const User & u)
{
	if (isFull())
	{
		resize();
	}

	increaseTop();
	arr[getTop()] = u;
}

void PowerUser::setReputation(int rep)
{
	this->Reputation = rep;
}

void PowerUser::increaseReputation()
{
	this->Reputation++;
}

const int PowerUser::getReputation() const
{
	return this->Reputation;
}

PowerUser::PowerUser()
{
	setReputation(0);
	setTop(EMPTY_ARR);
	setCapacity(3);
	this->arr = new User[getCapacity()];
}

PowerUser::PowerUser(const char * IPaddress, const char * Username, const char * Password, const char * Title) :
	User(IPaddress, Username, Password, Title)
{
	setReputation(0);
	setTop(EMPTY_ARR);
	setCapacity(3);
	this->arr = new User[getCapacity()];
}

PowerUser::PowerUser(const PowerUser & p) :
	User(p)
{
	copy(p);
}

PowerUser & PowerUser::operator=(const PowerUser & p)
{
	if (this != &p)
	{		
		User::operator=(p);
		delete[] arr;
		copy(p);
	}
	return *this;
}

PowerUser::~PowerUser()
{
	delete[] this->arr;
}

void PowerUser::receiveRep(const User & u)
{
	if (strcmp(u.getUsername(), this->getUsername()) == 0)
	{
		std::cout << "Error! You cannot give reputation to yourself!" << std::endl;
	}

	for (int i = 0; i <= getTop(); i++)
	{
		if (strcmp(u.getIPaddress(), this->arr[i].getIPaddress()) == 0)
		{
			std::cout << "Error! This user cannot give reputation!" << std::endl;
			return;
		}
	}

	increaseReputation();
	std::cout << "The reputation is increased to " << getReputation() << std::endl;
	addToArr(u);
}

void PowerUser::printDetails() const
{
	User::printDetails();
	std::cout << "Reputation: " << getReputation() << std::endl;
	if (isEmpty())
	{
		std::cout << "No users have given reputation!" << std::endl;
	}
	else
	{
		std::cout << "The users who have given reputation are: " << std::endl;
		for (int i = 0; i < getTop(); i++)
		{
			std::cout << this->arr[i].getUsername() << ",  ";
		}
		std::cout << this->arr[getTop()].getUsername() << ";" << std::endl;
	}
}