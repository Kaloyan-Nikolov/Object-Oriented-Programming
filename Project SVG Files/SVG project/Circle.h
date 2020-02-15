#pragma once
#include "BasicShape.h"

class Circle : public BasicShape
{
private:
	Point centre;
	int r;
	string fill;

public:
	void setCentre(const int cx, const int cy);
	const Point getCentre() const;
	void setR(const int r);
	const int getR() const;
	void setFill(const string fill);
	const string getFill() const;

	void setAll(const int cx, const int cy, const int r, const string fill);
	bool doExist(const int r) const;
	bool isVisible(const int cx, const int cy, const int r) const;
	bool applyParameters(const int cx, const int cy, const int r, const string fill);

	Circle();
	Circle(const int cx, const int cy, const int r, const string fill);
	virtual ~Circle();

	virtual void print() const override;
	virtual void printInFile(ofstream& myFile) const override;
	virtual bool getParameters(string & input) override;
	virtual bool readParameters(const string& row) override;
	virtual bool translate(int vertical, int horizontal) override;
	virtual bool isWithinCircle(int cxCircle, int cyCircle, int rCircle) const override;
	virtual bool isWithinRect(int xRect, int yRect, int widthRect, int heightRect) const override;
};