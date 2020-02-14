#include "Point3D.h"

void Point3D::setZ(const double z)
{
	this->z = z;
}

const double Point3D::getZ() const
{
	return this->z;
}

Point3D::Point3D()
{
	setZ(0);
}

Point3D::Point3D(const double x, const double y, const double z) :
	Point2D(x, y)
{
	setZ(z);
}

Point3D::~Point3D()
{
}

double Point3D::getDistanceTo(const Point3D & p) const
{
	double distance = sqrt((getX() - p.getX())*(getX() - p.getX())
		+ (getY() - p.getY())*(getY() - p.getY())
		+ (getZ() - p.getZ())*(getZ() - p.getZ()));
	return distance;
}

void Point3D::print() const
{
	cout << "(" << getX() << ", " << getY();
	cout << ", " << getZ() << ")" << endl;
}