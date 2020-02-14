#include "Point2D.h"

void Point2D::setX(const double x)
{
	this->x = x;
}

const double Point2D::getX() const
{
	return this->x;
}

void Point2D::setY(const double y)
{
	this->y = y;
}

const double Point2D::getY() const
{
	return this->y;
}

Point2D::Point2D()
{
	setX(0);
	setY(0);
}

Point2D::Point2D(const double x, const double y)
{
	setX(x);
	setY(y);
}

Point2D::~Point2D()
{
}

double Point2D::getDistanceTo(const Point2D & p) const
{
	double distance = sqrt((getX() - p.getX())*(getX() - p.getX())
		+ (getY() - p.getY())*(getY() - p.getY()));
	return distance;
}

void Point2D::print() const
{
	cout << "(" << getX() << ", " << getY() << ")" << endl;
}