#pragma once
#include "Entity.h"
#include "Player.h"
#include "Mob.h"
#include "NPC.h"
#include <vector>

class Environment
{
private:
	static Environment* Instance;
	vector<Entity*> arr;

	Environment();
	Environment(const Environment &env);
	Environment& operator=(const Environment &env);
	~Environment();
public:	
	//function to get the only instance - if such exists it
	//returns it, if not creates one;
	static Environment* getInstance();
	//function to release the instance when it is not longer needed;
	static void releaseInstance();

	void addPlayer(string name, Point2D* location,
		const int damage, const int health);
	void addMob(string name, Point2D* location,
		const int damage, const int health);
	void addNPC(string name, Point2D* location);
	Entity* getAt(int index);
	void removeAt(int index);
	void generateEntities();
	void destroyEntities();
	Entity* getClosestAliveEntity(const Player& p, type t);

	void printAllEntities() const;

	void attackAllMobs(const Player& p);
};