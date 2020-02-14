#pragma once
#include "GameCharacter.h"

class Guardian : public GameCharacter
{
public:
	Guardian();
	void printInfo() const override;
};