#pragma once
#include "Entity.h"

class Mortal : public Entity
{
private:
	int damage;
	int health;

public:
	void setDamage(const int damage);
	const int getDamage() const;
	void setHealth(const int health);
	const int getHealth() const;

	Mortal();
	Mortal(string name, Point2D* location, type t,
		const int damage, const int health);
	virtual ~Mortal();
	// copy constructor and operator= not needed because
	// we do not use dynamic memory

	bool isAlive() const override;
	virtual void attack(Mortal* m) const = 0;

	virtual void print() const override;
};