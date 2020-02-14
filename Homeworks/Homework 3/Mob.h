#pragma once
#include "Mortal.h"
#include "Player.h"

class Mob : public Mortal
{
public:
	Mob();
	Mob(string name, Point2D* location,
		const int damage, const int health);
	virtual ~Mob();

	virtual void attack(Mortal* m) const override;

	virtual void print() const override;
};