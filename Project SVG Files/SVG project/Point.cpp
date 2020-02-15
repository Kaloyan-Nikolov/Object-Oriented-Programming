#include "Point.h"

void Point::setX(const int x)
{
	this->x = x;
}

const int Point::getX() const
{
	return this->x;
}

void Point::setY(const int y)
{
	this->y = y;
}

const int Point::getY() const
{
	return this->y;
}

Point::Point()
{
	setX(0);
	setY(0);
}

Point::Point(const int x, const int y)
{
	setX(x);
	setY(y);
}

Point::~Point()
{
}

bool Point::isTheSameAs(const Point & p) const
{
	bool isXtheSame = (getX() == p.getX());
	bool isYtheSame = (getY() == p.getY());
	return (isXtheSame && isYtheSame);	
}

double Point::distanceFromPoint(const Point& p) const
{
	double distance = sqrt((getX() - p.getX())*(getX() - p.getX())
		+ (getY() - p.getY())*(getY() - p.getY()));
	return distance;
}

bool Point::isInCircle(const Point & centre, const int radius) const
{
	if (distanceFromPoint(centre) <= radius)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Point::isInRectangle(Point TopLeft, Point BottomRight) const
{	
	bool isXok = (getX() >= TopLeft.getX()) && (getX() <= BottomRight.getX());
	bool isYok = (getY() >= TopLeft.getY()) && (getY() <= BottomRight.getY());
	bool result = (isXok && isYok);
	return result;
}

void Point::printPoint() const
{
	cout << "(" << getX() << "," << getY() << ")" << endl;
}
