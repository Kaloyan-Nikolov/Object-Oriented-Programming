#pragma once
#include "Entity.h"

class NPC : public Entity
{
public:
	NPC();
	NPC(string name, Point2D* location);
	virtual ~NPC();

	virtual bool isAlive() const override;

	virtual void print() const override;
};