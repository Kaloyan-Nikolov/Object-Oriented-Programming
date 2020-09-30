#pragma once
#include "WebPage.h"

class Browser
{
private:
	WebPage* arr = nullptr;
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
public:
	Browser();
	Browser(const Browser& wp);
	Browser& operator=(const Browser& wp);
	~Browser();

	void add(const WebPage& wp);
	void remove(int index);
	void operator+=(const WebPage& wp);
	void operator-=(int index);

	void print()const;
};