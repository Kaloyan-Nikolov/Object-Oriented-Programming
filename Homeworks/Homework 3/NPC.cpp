#include "NPC.h"

NPC::NPC()
{
	setType(ENUM_NPC);
}

NPC::NPC(string name, Point2D * location) :
	Entity(name, location, ENUM_NPC)
{
}

NPC::~NPC()
{
}

bool NPC::isAlive() const
{
	return true;
}

void NPC::print() const
{
	cout << "Info of NPC: " << endl;
	Entity::print();
}