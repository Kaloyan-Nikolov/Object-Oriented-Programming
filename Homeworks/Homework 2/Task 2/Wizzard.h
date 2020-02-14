#pragma once
#include "GameCharacter.h"

class Wizzard : public GameCharacter
{
public:
	Wizzard();	
	void printInfo() const override;
};