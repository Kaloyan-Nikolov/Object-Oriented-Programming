#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Point
{
private:
	int x;
	int y;

public:
	void setX(const int x);
	const int getX() const;
	void setY(const int y);
	const int getY() const;

	Point();
	Point(const int x, const int y);
	virtual ~Point();

	bool isTheSameAs(const Point& p) const;
	double distanceFromPoint(const Point& p) const;	
	bool isInCircle(const Point& centre, const int radius) const;
	bool isInRectangle(Point TopLeft, Point BottomRight) const;

	void printPoint() const;
};