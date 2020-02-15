#include "BasicShape.h"

void BasicShape::setName(const string name)
{
	this->name = name;
}

const string BasicShape::getName() const
{
	return this->name;
}

BasicShape::BasicShape()
{
	setName("default figute");
}

BasicShape::BasicShape(const string name)
{
	setName(name);
}

BasicShape::~BasicShape()
{
}