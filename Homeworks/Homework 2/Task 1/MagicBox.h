#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

const int NO_MAGIC_OBJECTS = -1;

template <typename T>
class MagicBox
{
private:
	T* arr = nullptr;
	int top;
	int capacity;

	void increaseTop();
	void decreaseTop();
	void setTop(int top);
	int getTop() const;

	void setCapacity(int capacity);
	int getCapacity() const;

	bool isEmpty() const;
	bool isFull() const;

	void resize();
	void copy(const MagicBox<T> & m);

public:
	MagicBox();
	MagicBox(const MagicBox<T> & m);
	MagicBox<T>& operator=(const MagicBox<T> &m);
	~MagicBox();

	void insert(const T &a);
	void pop();
	void list() const;
};

template<typename T>
void MagicBox<T>::increaseTop()
{
	top++;
}

template<typename T>
void MagicBox<T>::decreaseTop()
{
	top--;
}

template<typename T>
void MagicBox<T>::setTop(int top)
{
	this->top = top;
}

template<typename T>
int MagicBox<T>::getTop() const
{
	return this->top;
}

template<typename T>
void MagicBox<T>::setCapacity(int capacity)
{
	this->capacity = capacity;
}

template<typename T>
int MagicBox<T>::getCapacity() const
{
	return this->capacity;
}

template<typename T>
bool MagicBox<T>::isEmpty() const
{
	return getTop() == NO_MAGIC_OBJECTS;
}

template<typename T>
bool MagicBox<T>::isFull() const
{
	return getCapacity() == getTop() + 1;
}

template<typename T>
void MagicBox<T>::resize()
{
	int newCapacity = getCapacity() * 2;
	T* newArr = new T[newCapacity];
	for (int i = 0; i <= getTop(); i++)
	{
		newArr[i] = this->arr[i];
	}
	delete[] this->arr;
	this->arr = newArr;
	setCapacity(newCapacity);
}

template<typename T>
void MagicBox<T>::copy(const MagicBox<T>& m)
{
	setTop(m.getTop());
	setCapacity(m.getCapacity());
	this->arr = new T[getCapacity()];

	for (int i = 0; i <= getTop(); i++)
	{
		this->arr[i] = m.arr[i];
	}
}

template<typename T>
MagicBox<T>::MagicBox()
{
	setTop(NO_MAGIC_OBJECTS);
	setCapacity(1);
	this->arr = new T[getCapacity()];
}

template<typename T>
MagicBox<T>::MagicBox(const MagicBox<T>& m)
{
	copy(m);
}

template<typename T>
MagicBox<T>& MagicBox<T>::operator=(const MagicBox<T>& m)
{
	if (this != &m)
	{
		delete[] this->arr;
		copy(m);
	}
	return *this;
}

template<typename T>
MagicBox<T>::~MagicBox()
{
	delete[] this->arr;
}

template<typename T>
void MagicBox<T>::insert(const T & a)
{
	if (isFull())
	{
		resize();
	}

	increaseTop();
	arr[getTop()] = a;
}

template<typename T>
void MagicBox<T>::pop()
{
	if (isEmpty())
	{
		std::cout << "The magic box is empty!" << std::endl;
		return;
	}

	int randomNumber = 0;
	randomNumber = (rand() % (getTop() + 1));
	std::cout << "Random number: " << randomNumber << std::endl;

	std::cout << "Excluded object: " << this->arr[randomNumber] << std::endl;
	for (int i = randomNumber; i < getTop(); i++)
	{
		this->arr[i] = this->arr[i + 1];
	}
	decreaseTop();
}

template<typename T>
void MagicBox<T>::list() const
{
	if (isEmpty())
	{
		std::cout << "The magic box is empty!" << std::endl;
		return;
	}

	std::cout << "The objects in the magic box are: " << std::endl;

	for (int i = 0; i < getTop(); i++)
	{
		std::cout << arr[i] << "\t";
	}
	std::cout << arr[getTop()] << std::endl;
}