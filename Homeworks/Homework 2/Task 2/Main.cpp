#include "GameCharacter.h"
#include "Warrior.h"
#include "Guardian.h"
#include "Wizzard.h"

using namespace std;

void test_Warrior()
{
	Warrior Spearmen;
	Warrior Knignt;

	for (int i = 0; i < 8; i++)
	{
		Spearmen.getattacked(Knignt.getAP());
		Spearmen.printInfo();
	}	
}

void test_Guardian()
{
	Guardian Protector;
	Warrior Knignt;

	for (int i = 0; i <= 40; i++)
	{
		Protector.getattacked(Knignt.getAP());
		if ((i % 10) == 0)
		{
			Protector.printInfo();
		}
	}
}

void test_pointers()
{
	Warrior Rambo;
	Guardian Protector;
	Wizzard Magician;	

	GameCharacter *Ptr1 = nullptr;
	GameCharacter *Ptr2 = nullptr;	
	
	Ptr1 = &Rambo;
	Ptr1->printInfo();

	Ptr2 = &Protector;
	Ptr2->printInfo();
	Ptr2 = &Magician;
	Ptr2->printInfo();

	Ptr2->getattacked(Ptr1->getAP());
	Ptr2->printInfo();
	
}

int main()
{	
	Warrior Rambo;
	Guardian Protector;
	Wizzard Magician;	

	Rambo.printInfo();
	Protector.printInfo();
	Magician.printInfo();

	Rambo.getattacked(Protector.getAP());
	Rambo.getattacked(Magician.getAP());

	Protector.getattacked(Rambo.getAP());
	Protector.getattacked(Magician.getAP());

	Magician.getattacked(Rambo.getAP());
	Magician.getattacked(Protector.getAP());

	cout << "After the fight: " << endl << endl;
	Rambo.printInfo();
	Protector.printInfo();
	Magician.printInfo();

	cout << "-------------" << endl << endl;;

	for (int i = 0; i <= 15; i++)
	{
		Magician.getattacked(Rambo.getAP());
	}
	cout << endl;
	Magician.printInfo();
	

	//test_Warrior();
	//test_Guardian();
	//test_pointers();

	int x = 0;
	cin >> x;
	return 0;
}