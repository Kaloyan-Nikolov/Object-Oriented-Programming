#include "Environment.h"

const double MAX_DISTANCE = 1000;

Environment * Environment::Instance = nullptr;

Environment::Environment()
{
}

Environment::Environment(const Environment & env)
{
}

Environment & Environment::operator=(const Environment & env)
{
	return *this;
}

Environment::~Environment()
{
	unsigned int size = arr.size();	

	for (unsigned int i = 0; i < size; i++)
	{
		delete arr[i];
	}
}

Environment * Environment::getInstance()
{
	if (Instance == nullptr)
	{
		Instance = new Environment();
	}
	else
	{
		return Instance;
	}	
}

void Environment::releaseInstance()
{
	if (Instance != nullptr)
	{
		delete Instance;
		Instance = nullptr;
	}
}

void Environment::addPlayer(string name, Point2D * location, const int damage, const int health)
{
	Player* p = new Player(name, location, damage, health);
	Entity* entityPtr = nullptr;
	entityPtr = p;
	this->arr.push_back(entityPtr);
}

void Environment::addMob(string name, Point2D * location, const int damage, const int health)
{
	Mob* m = new Mob(name, location, damage, health);
	Entity* entityPtr = nullptr;
	entityPtr = m;
	this->arr.push_back(entityPtr);
}

void Environment::addNPC(string name, Point2D * location)
{
	NPC* Npc = new NPC(name, location);
	Entity* entityPtr = nullptr;
	entityPtr = Npc;
	this->arr.push_back(entityPtr);
}


Entity * Environment::getAt(int index)
{
	return arr[index - 1];
}

void Environment::removeAt(int index)
{
	unsigned int size = arr.size();

	if (size == 0)
	{
		cout << "Error! No entities entered!" << endl;
		return;
	}

	// if the user wants to erase the first shape he writes 1, not 0;
	int realIndex = index - 1;	

	if (realIndex < 0 || realIndex >= size)
	{
		cout << "Error! Invalid index!";
		cout << " There is no entity number " << index << "!" << endl;
		return;
	}
	
	delete arr[realIndex];
	arr.erase(arr.begin() + realIndex);	
}

void Environment::generateEntities()
{
	Point2D* p1 = new Point2D(4, 5);
	Point3D* p2 = new Point3D(3, 4, 7);
	Point2D* p3 = new Point2D(5, 6);
	Point3D* p4 = new Point3D(2, 3, 7);
	Point3D* p5 = new Point3D(10, 1, 2);
	Point2D* p6 = new Point2D(1, 1);
	Point2D* p7 = new Point2D(10, 12);
	Point3D* p8 = new Point3D(8, 8, 5);
	Point2D* p9 = new Point2D(5, 5);

	Environment::getInstance()->addPlayer("wizzard", p1, 50, 200);
	Environment::getInstance()->addPlayer("giant", p2, 30, 180);
	Environment::getInstance()->addMob("first mob", p3, 25, 400);
	Environment::getInstance()->addMob("second mob", p4, 20, 300);
	Environment::getInstance()->addNPC("first npc", p5);
	Environment::getInstance()->addNPC("second npc", p6);
	Environment::getInstance()->addMob("thrid mob", p7, 30, 280);
	Environment::getInstance()->addPlayer("warrior", p8, 60, 150);
	Environment::getInstance()->addNPC("third npc", p9);

	delete p1;
	delete p2;
	delete p3;
	delete p4;
	delete p5;
	delete p6;
	delete p7;
	delete p8;
	delete p9;
}

void Environment::destroyEntities()
{
	unsigned int size = arr.size();	

	for (unsigned int i = 0; i < size; i++)
	{
		delete arr[i];
	}
	arr.clear();
}

Entity * Environment::getClosestAliveEntity(const Player & p, type t)
{	
	Entity* closestEntity = nullptr;

	unsigned int size = arr.size();

	if (size == 0)
	{
		cout << "Error! No entities entered!" << endl;
		return nullptr;
	}

	double smallestDistanceFound = MAX_DISTANCE;
	double currentDistance;
	for (unsigned int i = 0; i < size; i++)
	{
		currentDistance = p.getDistanceTo(*arr[i]);
		bool isCurrentDistanceSmaller = (smallestDistanceFound > currentDistance);
		bool isLiving = arr[i]->isAlive();
		bool isIdOK = arr[i]->getId() != p.getId();
		bool isTypeOk = arr[i]->getType() == t;
		if (isCurrentDistanceSmaller && isLiving && isIdOK && isTypeOk)
		{
			closestEntity = arr[i];
			smallestDistanceFound = currentDistance;
		}
	}

	return closestEntity;
}

void Environment::printAllEntities() const
{
	unsigned int size = arr.size();

	if (size == 0)
	{
		cout << "Error! No entities entered!" << endl;
		return;
	}

	for (unsigned int i = 0; i < size; i++)
	{
		cout << "Entity number " << i + 1 << endl;
		arr[i]->print();
		if ((i + 1) < size)
		{
			cout << "--------------------" << endl;
		}
	}
}

void Environment::attackAllMobs(const Player & p)
{
	// here we will save the distance to the different mobs;
	vector<double>distanceToMobs;
	
	unsigned int size = arr.size();

	/*
	for (unsigned int i = 0; i < size; i++)
	{
		if (arr[i]->getType() == ENUM_MOB)
		{
			double newDistance = arr[i]->getDistanceTo(p);
			distanceToMobs.push_back(newDistance);
		}
	}
	*/

	for (vector<Entity*>::iterator iter = arr.begin(); iter != arr.end(); ++iter)
	{
		if ((*iter)->getType() == ENUM_MOB)
		{
			double newDistance = (*iter)->getDistanceTo(p);
			distanceToMobs.push_back(newDistance);
		}
	}
	
	unsigned int numMobs = distanceToMobs.size();

	// selection sort for distanceToMobs
	// the smallest distance should become last element of the vector;
	
	for (unsigned int i = 0; i < numMobs - 1; i++)
	{
		double biggestDistance = distanceToMobs[i];
		int indexBiggestDistance = i;

		for (unsigned int j = i + 1; j < numMobs; j++)
		{
			if (biggestDistance < distanceToMobs[j])
			{
				biggestDistance = distanceToMobs[j];
				indexBiggestDistance = j;
			}
		}

		double temp = distanceToMobs[i];
		distanceToMobs[i] = biggestDistance;
		distanceToMobs[indexBiggestDistance] = temp;
	}

	// now we have to find the mob in the corresponding distance,
	// attack the mob and push_back the distance;

	while (numMobs > 0)
	{
		for (unsigned int i = 0; i < size; i++)
		{
			if (arr[i]->getDistanceTo(p) == distanceToMobs[numMobs-1])
			{
				Mortal* mobPtr = dynamic_cast<Mortal*>(arr[i]);
				p.attack(mobPtr);
				distanceToMobs.pop_back();
				numMobs--;
				break;
			}
		}
	}
}