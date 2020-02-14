#pragma once
#include <iostream>

class IntStack
{
private:
	int* arr = nullptr;
	int top;		// the index of last element in stack
	int capacity;	// how many element the stack can contain

	void increaseTop();
	void decreaseTop();
	void setTop(int top);
	int getTop() const;

	void setCapacity(int capacity);
	int getCapacity() const;

	bool isFull() const;
	void resize(); // doubles the capacity of the stack

	void copy(const IntStack& a); // the code which will be used in both 
								  // copy constructor and operator=

public:
	IntStack();

	IntStack(const IntStack &a);

	IntStack& operator=(const IntStack &a);

	~IntStack();

	bool isEmpty() const;

	int peek() const; 

	void push(int number);

	int pop();

	void print() const;

	friend IntStack sortStack(const IntStack &a);
};
