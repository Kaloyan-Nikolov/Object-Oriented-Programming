#pragma once
#include <iostream>
using namespace std;

class GameCharacter
{
private:
	char* name = nullptr;
	int HP;
	int MP;
	int AP;
	int DP;

	void copy(const GameCharacter& ch);	

protected: // this way the setters cannot be accessed from Main
	void setName(const char* name);
	void setHP(int HP);
	void setMP(int MP);
	void setAP(int AP);
	void setDP(int DP);

public:	
	const char* getName() const;	
	const int getHP() const;	
	const int getMP() const;	
	const int getAP() const;	
	const int getDP() const;

	GameCharacter();
	GameCharacter(const char* name, int HP, int MP, int AP, int DP);
	GameCharacter(const GameCharacter& ch);
	GameCharacter& operator=(const GameCharacter& ch);
	virtual ~GameCharacter(); 

	bool isAlive() const;

	void getattacked(int AP);
	virtual void printInfo() const = 0; // this way the class is abstract
};