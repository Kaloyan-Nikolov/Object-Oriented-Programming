#include "Wizzard.h"

Wizzard::Wizzard() : GameCharacter("Wizzard", 30, 30, 2, 2)
{
}

void Wizzard::printInfo() const
{
	std::cout << "Characteristics of the Wizzard: " << std::endl;
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
