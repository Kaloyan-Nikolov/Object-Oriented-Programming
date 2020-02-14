#include "Warrior.h"

Warrior::Warrior() : GameCharacter("Warrior", 20, 5, 4, 1)
{
}

void Warrior::printInfo() const
{
	std::cout << "Characteristics of the Warrior: " << std::endl;
	std::cout << "Name: " << getName() << std::endl;
	std::cout << "HP: " << getHP() << std::endl;
	std::cout << "MP: " << getMP() << std::endl;
	std::cout << "AP: " << getAP() << std::endl;
	std::cout << "DP: " << getDP() << std::endl;
	if (isAlive() == false)
	{
		std::cout << "The " << getName() << " is dead!" << std::endl;
	}
	std::cout << std::endl;
}
