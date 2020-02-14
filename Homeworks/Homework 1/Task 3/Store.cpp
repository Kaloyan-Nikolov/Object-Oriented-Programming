#include "Store.h"

const int EMPTY_STORE = -1;

void Store::increaseTop()
{
	top++;
}

void Store::descreaseTop()
{
	top--;
}

void Store::setTop(int top)
{
	if (top >= EMPTY_STORE)
	{
		this->top = top;
	}
}

int Store::getTop() const
{
	return this->top;
}

void Store::setCapacity(int capacity)
{
	if (capacity > 0)
	{
		this->capacity = capacity;
	}
}

int Store::getCapacity() const
{
	return this->capacity;
}

bool Store::isEmpty() const
{
	return (getTop() == EMPTY_STORE);
}

bool Store::isFull() const
{
	return (getTop() == getCapacity() - 1);
}

void Store::resize()
{
	int NewCapacity = getCapacity() * 2;
	Product* newArr = new Product[NewCapacity];
	for (int i = 0; i < getCapacity(); i++)
	{
		newArr[i].move(arr[i]);
	}
	delete[] arr;
	arr = newArr;
	setCapacity(NewCapacity);
}

void Store::copy(const Store & a)
{
	setTop(a.getTop());
	setCapacity(a.getCapacity());
	arr = new Product[getCapacity()];

	for (int i = 0; i <= top; i++)
	{
		arr[i] = a.arr[i];
	}
}


Store::Store()
{
	setTop(EMPTY_STORE);
	setCapacity(1);
	this->arr = new Product[getCapacity()];
}

Store::Store(const Store & p)
{
	copy(p);
}

Store & Store::operator=(const Store & p)
{
	if (this != &p)
	{
		delete[] this->arr;
		copy(p);
	}

	return *this;
}

void Store::add(const Product & p)
{
	if (isFull())
	{
		resize();
	}

	increaseTop();
	arr[getTop()].move(p);
}

void Store::remove(unsigned int position)
{
	int realPosition = position - 1;

	if (isEmpty())
	{
		std::cout << "Error! The store is empty." << std::endl;
		return;
	}

	if (realPosition > getTop() || realPosition < 0)
	{
		std::cout << "Error! Incorrect position!" << std::endl;
		return;
	}

	for (int i = realPosition; i < getTop(); i++)
	{
		arr[i].move(arr[i + 1]);		
	}

	descreaseTop();
	std::cout << "The product has been deleted successfully!" << std::endl;
}

void Store::change(unsigned int position, const Product & p)
{
	int realPosition = position - 1;

	if (isEmpty())
	{
		std::cout << "Error! The store is empty." << std::endl;
		return;
	}

	if (realPosition > getTop() || realPosition < 0)
	{
		std::cout << "Error! Incorrect position!" << std::endl;
		return;
	}

	arr[realPosition].copyWithoutSKU(p);
	std::cout << "The product has been changed successfully!" << std::endl;	
}

void Store::printStore() const
{
	if (isEmpty())
	{
		std::cout << "The store is empty!" << std::endl;
	}
	else
	{
		std::cout << "The products in the store are:" << std::endl;
		for (int i = 0; i <= getTop(); i++)
		{
			std::cout << "Info for product #" << i + 1 << " : " << std::endl;
			arr[i].print();
		}
	}
}

Store::~Store()
{
	delete[] arr;
}
