#include "Mortal.h"

void Mortal::setDamage(const int damage)
{
	if (damage > 0)
	{
		this->damage = damage;
	}
}

const int Mortal::getDamage() const
{
	return this->damage;
}

void Mortal::setHealth(const int health)
{
	if (health >= 0)
	{
		this->health = health;
	}
}

const int Mortal::getHealth() const
{
	return this->health;
}

Mortal::Mortal()
{
	setType(ENUM_PLAYER);
	setDamage(10);
	setHealth(100);
}

Mortal::Mortal(string name, Point2D * location, type t,
	const int damage, const int health) :
	Entity(name, location, t)
{
	setDamage(damage);
	setHealth(health);
}

Mortal::~Mortal()
{
}

bool Mortal::isAlive() const
{
	if (getHealth() > 0)
	{
		return true;
	}

	return false;
}

void Mortal::print() const
{
	Entity::print();
	cout << "Damage: " << getDamage() << endl;
	cout << "Health: " << getHealth() << endl;
}