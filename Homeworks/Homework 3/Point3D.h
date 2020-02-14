#pragma once
#include "Point2D.h"

class Point3D : public Point2D
{
private:
	double z;

public:
	void setZ(const double z);
	const double getZ() const;

	Point3D();
	Point3D(const double x, const double y, const double z);
	virtual ~Point3D();

	double getDistanceTo(const Point3D& p) const;

	virtual void print() const override;
};