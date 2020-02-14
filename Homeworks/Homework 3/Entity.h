#pragma once
#include "Point3D.h"
#include <string>

enum type
{
	ENUM_PLAYER = 0,
	ENUM_NPC = 1,
	ENUM_MOB = 2
};

class Entity
{
private:
	static int UniqueID;
	int id;
	string name;
	Point2D* location = nullptr;
	type t;

	void changeLoc(Point2D p);

public:
	void increaseUniqueID();
	const int getCurrentId() const;
	void setId();
	void copyId(const Entity& e);
	const int getId() const;
	void setName(string name);
	string getName() const;
	void setLocation(Point2D* location);
	Point2D* getLocation() const;
	void setType(const type& t);
	const type getType() const;
	
	Entity();
	Entity(string name, Point2D* location, type t);
	Entity(const Entity& e);
	Entity& operator=(const Entity& e);
	virtual ~Entity();

	virtual void print() const;

	virtual bool isAlive() const = 0;
	double getDistanceTo2D(const Entity& e) const;
	double getDistanceTo(const Entity& e) const;
	void moveTo(Point2D* p);
	void moveTo(const Entity &e);
};