#pragma once
#include "BasicShape.h"

class Rect : public BasicShape
{
private:
	Point topLeftPoint;	
	int width;
	int height;
	string fill;

public:
	void setTopLeftPoint(const int x, const int y);
	const Point getTopLeftPoint() const;
	void setWidth(const int width);
	const int getWidth() const;
	void setHeight(const int height);
	const int getHeight() const;
	void setFill(const string fill);
	const string getFill() const;

	void setAll(const int x, const int y, const int width, const int height, const string fill);
	bool doExist(const int width, const int height) const;
	bool isVisible(const int x, const int y) const;
	bool applyParameters(const int x, const int y, const int width, const int height, const string fill);

	Rect();
	Rect(const int x, const int y, const int width, const int height, const string fill);
	virtual ~Rect();

	
	const Point getTopRightPoint() const;
	const Point getBottomLeftPoint() const;
	const Point getBottomRightPoint() const;


	virtual void print() const override;
	virtual void printInFile(ofstream& myFile) const override;
	virtual bool getParameters(string & input) override;
	virtual bool readParameters(const string& row) override;
	virtual bool translate(int vertical, int horizontal) override;
	virtual bool isWithinCircle(int cxCircle, int cyCircle, int rCircle) const override;
	virtual bool isWithinRect(int xRect, int yRect, int widthRect, int heightRect) const override;
};