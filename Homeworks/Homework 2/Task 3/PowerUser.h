#pragma once
#include "User.h"

class PowerUser : virtual public User
{
private:
	int Reputation;
	User* arr = nullptr; //containing the users who have given 1 reputation and preventing them to give reputation again
	int top; // index of last element
	int capacity; // maximum number of elements

	void increaseTop();
	void setTop(int top);
	const int getTop() const;

	void setCapacity(int capacity);
	const int getCapacity() const;

	bool isEmpty() const;
	bool isFull() const;
	void resize();

	void copy(const PowerUser &p);
	void addToArr(const User &u);

protected:
	void setReputation(int rep);

public:
	void increaseReputation();
	const int getReputation() const;

	PowerUser();
	PowerUser(const char * IPaddress, const char* Username, const char* Password, const char* Title);
	PowerUser(const PowerUser &p);
	PowerUser& operator=(const PowerUser &p);
	virtual ~PowerUser();

	void receiveRep(const User &u);

	virtual void printDetails() const override;
};
