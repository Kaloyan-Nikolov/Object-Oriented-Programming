#pragma once
#include "Product.h"

class Store
{
private:
	Product* arr = nullptr;
	int top;
	int capacity;

	void increaseTop();
	void descreaseTop();
	void setTop(int top);
	int getTop() const;

	void setCapacity(int capacity);
	int getCapacity() const;

	bool isEmpty() const;
	bool isFull() const;
	void resize();
	void copy(const Store &a);

public:
	Store();
	Store(const Store& p);
	Store& operator=(const Store& p);

	void add(const Product& p);
	void remove(unsigned int position);
	void change(unsigned int position, const Product& p);
	void printStore() const;

	~Store();
};