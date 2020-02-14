#include "Guardian.h"

Guardian::Guardian() : GameCharacter("Guardian", 40, 25, 1, 3)
{
}

void Guardian::printInfo() const
{
	std::cout << "Characteristics of the Guardian: " << std::endl;
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
