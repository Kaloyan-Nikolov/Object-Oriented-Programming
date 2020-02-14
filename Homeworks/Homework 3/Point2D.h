#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Point2D
{
private:
	double x;
	double y;

public:
	void setX(const double x);
	const double getX() const;
	void setY(const double y);
	const double getY() const;

	Point2D();
	Point2D(const double x, const double y);
	virtual ~Point2D();

	double getDistanceTo(const Point2D& p) const;

	virtual void print() const;
};