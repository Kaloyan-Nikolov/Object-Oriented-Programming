#include "Player.h"

Player::Player()
{
	setType(ENUM_PLAYER);
	setDamage(10);
	setHealth(100);
}

Player::Player(string name, Point2D * location,
	const int damage, const int health) :
	Mortal(name, location, ENUM_PLAYER, damage, health)
{
}

Player::~Player()
{
}

void Player::attack(Mortal * m) const
{
	if (m->isAlive() == false)
	{
		return;
	}

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

void Player::print() const
{
	cout << "Info of player: " << endl;
	Mortal::print();
}