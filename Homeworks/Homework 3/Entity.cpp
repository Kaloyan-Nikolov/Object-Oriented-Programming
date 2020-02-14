#include "Entity.h"

int Entity::UniqueID = 1;

void Entity::changeLoc(Point2D p)
{
	location->setX(p.getX());
	location->setY(p.getY());
}

void Entity::increaseUniqueID()
{
	UniqueID++;
}

const int Entity::getCurrentId() const
{
	return this->UniqueID;
}

void Entity::setId()
{
	this->id = getCurrentId();
}

void Entity::copyId(const Entity & e)
{
	this->id = e.getId();
}

const int Entity::getId() const
{
	return this->id;
}

void Entity::setName(string name)
{
	this->name = name;
}

string Entity::getName() const
{
	return this->name;
}

void Entity::setLocation(Point2D * location)
{	
	delete this->location;	
	
	Point3D* p3D = dynamic_cast<Point3D*>(location);
	if (p3D != nullptr)
	{
		this->location = new Point3D(*p3D);
	}
	else
	{
		this->location = new Point2D(*location);
	}
}

Point2D * Entity::getLocation() const
{
	return this->location;
}

void Entity::setType(const type & t)
{
	this->t = t;
}

const type Entity::getType() const
{
	return this->t;
}

Entity::Entity()
{
	Point2D* p1 = new Point2D(0, 0);
	setId();
	increaseUniqueID();
	setName("Def name");
	setLocation(p1);
}

Entity::Entity(string name, Point2D * location, type t)
{
	setId();
	increaseUniqueID();
	setName(name);
	setLocation(location);
	setType(t);
}

Entity::Entity(const Entity & e) : location(nullptr)
{
	copyId(e);
	setName(e.getName());
	setLocation(e.getLocation());
	setType(e.getType());
}

Entity & Entity::operator=(const Entity & e)
{
	if (this != &e)
	{
		copyId(e);
		setName(e.getName());
		setLocation(e.getLocation());
		setType(e.getType());
	}

	return *this;
}

Entity::~Entity()
{
	delete location;
}

void Entity::print() const
{
	cout << "Id: " << getId() << endl;
	cout << "Name: " << getName() << endl;
	cout << "Location: ";
	getLocation()->print();	
}

double Entity::getDistanceTo2D(const Entity & e) const
{
	Point2D *tempLocation = dynamic_cast<Point2D*>(e.getLocation());
	double result = getLocation()->getDistanceTo(*tempLocation);
	return result;
}

double Entity::getDistanceTo(const Entity & e) const
{
	Point3D *tempReceivedLocation = dynamic_cast<Point3D*>(e.getLocation());
	Point3D *tempLocation = dynamic_cast<Point3D*>(getLocation());
	bool isReceivedLocOK = (tempReceivedLocation != nullptr);
	bool isLocationOK = (tempLocation != nullptr);

	double result;
	if (isReceivedLocOK && isLocationOK)
	{
		// find distance for 3d;
		result = tempReceivedLocation->getDistanceTo(*tempLocation);
	}
	else
	{
		// find distance for 2d;
		result = getLocation()->getDistanceTo(*(e.getLocation()));
	}
	return result;
}

void Entity::moveTo(Point2D * p)
{
	Point3D *tempReceivedLocation = dynamic_cast<Point3D*>(p);
	Point3D *tempLocation = dynamic_cast<Point3D*>(getLocation());
	bool isReceivedLocOK = (tempReceivedLocation != nullptr);
	bool isLocationOK = (tempLocation != nullptr);

	if (isReceivedLocOK && isLocationOK)
	{
		// find new loc for both 3d
		setLocation(p);

	}
	else // we have to copy only x and y from p
	{
		Point2D newLoc(p->getX(), p->getY());
		changeLoc(newLoc);
	}
}

void Entity::moveTo(const Entity & e)
{
	Point3D *tempReceivedLocation = dynamic_cast<Point3D*>(e.getLocation());
	Point3D *tempLocation = dynamic_cast<Point3D*>(getLocation());
	bool isReceivedLocOK = (tempReceivedLocation != nullptr);
	bool isLocationOK = (tempLocation != nullptr);

	if (isReceivedLocOK && isLocationOK)
	{
		// find new loc for both 3d
		setLocation(e.getLocation());
	}
	else // we have to copy only x and y from p
	{
		Point2D newLoc(e.getLocation()->getX(), e.getLocation()->getY());
		changeLoc(newLoc);
	}
}