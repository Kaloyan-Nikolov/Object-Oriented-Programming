#include "Mob.h"

Mob::Mob()
{
	setType(ENUM_MOB);
	setDamage(20);
	setHealth(200);
}

Mob::Mob(string name, Point2D * location,
	const int damage, const int health) :
	Mortal(name, location, ENUM_MOB,
		damage, health)
{
}

Mob::~Mob()
{
}

void Mob::attack(Mortal* m) const
{
	if (m->isAlive() == false)
	{
		return;
	}

	bool isPlayer = m->getType() == ENUM_PLAYER;
	if (isPlayer)
	{
		double distance = getDistanceTo(*m);
		if (distance < 5)
		{
			int remainingHealth = m->getHealth() - getDamage();
			if (remainingHealth > 0)
			{
				m->setHealth(remainingHealth);
			}
			else
			{
				m->setHealth(0);
			}
		}
	}
}

void Mob::print() const
{
	cout << "Info of mob: " << endl;
	Mortal::print();
}