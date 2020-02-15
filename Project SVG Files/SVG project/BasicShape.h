#pragma once
#include <fstream>
#include "Point.h"
#include "StringCheck.h"

class BasicShape
{
private:
	string name;

public:

	void setName(const string name);
	const string getName() const;

	BasicShape();
	BasicShape(const string name);
	virtual ~BasicShape();

	virtual void print() const = 0;
	virtual void printInFile(ofstream& myFile) const = 0;
	virtual bool getParameters(string& input) = 0;
	virtual bool readParameters(const string& row) = 0;
	virtual bool translate(int vertical, int horizontal) = 0;
	virtual bool isWithinCircle(int cxCircle, int cyCircle, int rCircle) const = 0;
	virtual bool isWithinRect(int xRect, int yRect, int widthRect, int heightRect) const = 0;

};