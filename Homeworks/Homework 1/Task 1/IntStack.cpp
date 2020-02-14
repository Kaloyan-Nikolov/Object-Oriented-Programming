#include "IntStack.h"

const int EMPTY_STACK = -1;

void IntStack::increaseTop()
{
	top++;
}

void IntStack::decreaseTop()
{
	top--;
}

void IntStack::setTop(int top)
{
	if (top >= EMPTY_STACK)
	{
		this->top = top;
	}
}

int IntStack::getTop() const
{
	return this->top;
}

void IntStack::setCapacity(int capacity)
{
	if (capacity > 0)
	{
		this->capacity = capacity;
	}
}

int IntStack::getCapacity() const
{
	return this->capacity;;
}

bool IntStack::isFull() const
{
	return (getTop() == getCapacity() - 1);
}

void IntStack::resize()
{
	int newCapacity = 2 * getCapacity();
	int* newArray = new int[newCapacity];
	for (int i = 0; i < capacity; i++)
	{
		newArray[i] = arr[i];
	}

	delete[] arr;
	arr = newArray;
	setCapacity(newCapacity);		
}

void IntStack::copy(const IntStack& a)
{
	setTop(a.getTop());
	setCapacity(a.getCapacity());
	arr = new int[getCapacity()];
	for (int i = 0; i <= top; i++)
	{
		arr[i] = a.arr[i];
	}
}

IntStack::IntStack()
{
	setTop(EMPTY_STACK);
	setCapacity(1);
	this->arr = new int[getCapacity()];
}

IntStack::IntStack(const IntStack & a)
{
	this->copy(a);
}

IntStack & IntStack::operator=(const IntStack & a)
{
	if (this != &a)
	{
		delete[] arr;
		this->copy(a);
	}
	
	return *this;
}

IntStack::~IntStack()
{
	delete[] arr;
}

bool IntStack::isEmpty() const
{
	return (getTop() == EMPTY_STACK);
}

int IntStack::peek() const
{
	if (isEmpty())
	{
		std::cout << "Error! The stack is empty." << std::endl;
		return EMPTY_STACK; 
	}
	
	return arr[top];
}

void IntStack::push(int number)
{
	if (isFull())
	{
		resize();
	}

	increaseTop();
	arr[top] = number;
}

int IntStack::pop()
{
	if (isEmpty())
	{
		std::cout << "Error! The stack is empty." << std::endl;
		return EMPTY_STACK; 
	}

	decreaseTop();
	return 	arr[top + 1];
}

void IntStack::print() const
{
	if (isEmpty())
	{
		std::cout << "Error! The stack is empty." << std::endl;
		return;
	}

	std::cout << "The elements of the stack are: " << std::endl;

	for (int i = getTop(); i > 0 ; i--) // all but first element
	{
		std::cout << arr[i] << ", ";
	}

	std::cout << arr[0] << ";" << std::endl; // the first element
}
