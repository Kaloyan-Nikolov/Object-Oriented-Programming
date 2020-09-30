#include "Browser.h"

const int NO_PAGES = -1;

void Browser::increaseTop()
{
	top++;
}

void Browser::descreaseTop()
{
	top--;
}

void Browser::setTop(int top)
{
	if (top >= NO_PAGES)
	{
		this->top = top;
	}
}

int Browser::getTop() const
{
	return this->top;
}

void Browser::setCapacity(int capacity)
{
	if (capacity > 0)
	{
		this->capacity = capacity;
	}
}

int Browser::getCapacity() const
{
	return this->capacity;
}

bool Browser::isEmpty() const
{
	return (getTop() == NO_PAGES);
}

bool Browser::isFull() const
{
	return (getTop() == getCapacity() - 1);
}

void Browser::resize()
{
	int newCapacity = getCapacity() * 2;
	WebPage* newArr = new WebPage[newCapacity];
	for (int i = 0; i <= getTop(); i++)
	{
		newArr[i] = arr[i];
	}
	delete[] this->arr;
	arr = newArr;
	setCapacity(newCapacity);
}

Browser::Browser()
{
	setTop(NO_PAGES);
	setCapacity(10);
	arr = new WebPage[getCapacity() + 1];
}

Browser::Browser(const Browser & wp)
{
	setTop(wp.getTop());
	setCapacity(wp.getCapacity());
	arr = new WebPage[getCapacity() + 1];
	for (int i = 0; i <= getTop(); i++)
	{
		arr[i] = wp.arr[i];
	}
}

Browser & Browser::operator=(const Browser & wp)
{
	if (this != &wp)
	{
		setTop(wp.getTop());
		setCapacity(wp.getCapacity());
		delete[] arr;
		arr = new WebPage[getCapacity() + 1];
		for (int i = 0; i <= getTop(); i++)
		{
			arr[i] = wp.arr[i];
		}
	}

	return *this;
}

Browser::~Browser()
{
	delete[] arr;
}

void Browser::add(const WebPage & wp)
{
	if (isFull())
	{
		resize();
	}

	increaseTop();
	arr[getTop()] = wp;
}

void Browser::remove(int index)
{
	int codeIndex = index - 1;

	if (isEmpty())
	{
		cout << "Error! No pages!" << endl;
		return;
	}

	if (index > top)
	{
		cout << "Error!" << endl;
		return;
	}

	for (int i = codeIndex; i < getTop(); i++)
	{
		arr[i] = arr[i + 1];
	}
	descreaseTop();
}

void Browser::operator+=(const WebPage & wp)
{
	add(wp);
}

void Browser::operator-=(int index)
{
	remove(index);
}

void Browser::print() const
{
	if (isEmpty())
	{
		cout << "Error! No pages!" << endl;
		return;
	}

	cout << "Browser: " << endl;
	for (int i = 0; i <= getTop(); i++)
	{
		cout << "Page: " << i + 1 << endl;
		cout << arr[i];
	}
}