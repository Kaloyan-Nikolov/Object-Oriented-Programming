#pragma once
#include "Mortal.h"

class Player : public Mortal
{
public:
	Player();
	Player(string name, Point2D* location,
		const int damage, const int health);
	virtual ~Player();

	virtual void attack(Mortal* m) const override;

	virtual void print() const override;
};