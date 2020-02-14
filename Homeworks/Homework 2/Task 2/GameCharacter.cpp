#include "GameCharacter.h"

void GameCharacter::copy(const GameCharacter & ch)
{
	setName(ch.getName());
	setHP(ch.getHP());
	setMP(ch.getMP());
	setAP(ch.getAP());
	setDP(ch.getDP());
}

void GameCharacter::setName(const char * name)
{
	if (name == nullptr)
	{
		return;
	}
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void GameCharacter::setHP(int HP)
{
	this->HP = HP;
}

void GameCharacter::setMP(int MP)
{
	this->MP = MP;
}

void GameCharacter::setAP(int AP)
{
	this->AP = AP;
}

void GameCharacter::setDP(int DP)
{
	this->DP = DP;
}

const char * GameCharacter::getName() const
{
	return this->name;
}

const int GameCharacter::getHP() const
{
	return this->HP;
}

const int GameCharacter::getMP() const
{
	return this->MP;
}

const int GameCharacter::getAP() const
{
	return this->AP;
}

const int GameCharacter::getDP() const
{
	return this->DP;
}

GameCharacter::GameCharacter()
{
	setName("Def character");
	setHP(10);
	setMP(1);
	setAP(3);
	setDP(1);
}

GameCharacter::GameCharacter(const char * name, int HP, int MP, int AP, int DP)
{
	setName(name);
	setHP(HP);
	setMP(MP);
	setAP(AP);
	setDP(DP);
}

GameCharacter::GameCharacter(const GameCharacter & ch)
{
	copy(ch);
}

GameCharacter & GameCharacter::operator=(const GameCharacter & ch)
{
	if (this != &ch)
	{		
		copy(ch);
	}
	return *this;
}

GameCharacter::~GameCharacter()
{
	delete[] this->name;
}

bool GameCharacter::isAlive() const
{
	return (HP > 0);
}

void GameCharacter::getattacked(int AP)
{
	if (isAlive() == false)
	{
		std::cout << "The " << getName() << " is already killed!" << std::endl;
		std::cout << "He cannot take part in battle!" << std::endl;
		return;
	}

	int lostHP = AP - this->getDP();
	if (lostHP > 0)
	{
		int remainingHP = this->getHP() - lostHP;
		setHP(remainingHP);
	}
	
	if (this->getHP() <= 0)
	{
		this->setHP(0);
		std::cout << "The " << getName() << " has been killed!" << std::endl;
	}
}