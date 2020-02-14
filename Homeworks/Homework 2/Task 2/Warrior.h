#pragma once
#include "GameCharacter.h"

class Warrior : public GameCharacter
{
public:
	Warrior();
	void printInfo() const override;
};