#include "Point2D.h"
#include "Point3D.h"
#include "Entity.h"
#include "Player.h"
#include "NPC.h"
#include "Mob.h"
#include "Environment.h"

void previous_tests()
{
	Point2D* p1 = new Point2D(4, 5);
	Point2D* p3 = new Point2D(5, 6);
	Point3D* p2 = new Point3D(3, 4, 7);
	Point3D* p4 = new Point3D(2, 3, 7);
	Point3D* p5 = new Point3D(10, 1, 2);
	Point2D* p6 = new Point2D(6, 5);
	
	p1->print();
	p2->print();

	cout << "___________________________________________" << endl << endl;

	Player player1("magician", p4, 50, 200);
	Player player2("giant", p3, 30, 180);
	Mob mob1("first mob", p2, 25, 400);
	Mob mob2("second mob", p1, 20, 300);
	double distance = player1.getDistanceTo(player2);
	cout << distance << endl;
	
	// TEST OF MOVE AND ATTACK
	cout << "___________________________________________" << endl << endl;
	player1.print();

	player1.moveTo(mob2);
	cout << endl;
	player1.print();

	player1.moveTo(p5);
	cout << endl;
	player1.print();

	cout << "___________________________________________" << endl << endl;

	player2.print();
	cout << endl;

	player1.attack(&player2);
	player2.print();

	cout << "___________________________________________" << endl << endl;

	cout << endl;
	mob1.print();
	mob1.attack(&player2);

	cout << endl;
	player2.print();

	cout << endl;
	cout << "___________________________________________" << endl;
	cout << "after 3 attacks: " << endl << endl;
	player1.attack(&player2);
	player1.attack(&player2);
	player1.attack(&player2);

	player2.print();

	cout << "___________________________________________" << endl << endl;

	cout << endl;
	mob1.print();
	mob1.attack(&mob2);

	cout << endl;
	mob2.print();	

	cout << "___________________________________________" << endl << endl;
	NPC npc1("first npc", p5);
	NPC npc2("second npc", p6);
	npc1.print();
	npc2.print();

	delete p1;
	delete p2;
	delete p3;
	delete p4;	
	delete p5;
	delete p6;
}

int main()
{	
	previous_tests();

	Point3D* point1 = new Point3D(3, 3, 6);
	Player player1("magician", point1, 60, 200);

	Environment::getInstance()->generateEntities();

	Environment::getInstance()->printAllEntities();

	cout << endl;
	cout << "___________________________________________" << endl << endl;
	cout << "closest is: " << endl;

	Environment::getInstance()->getClosestAliveEntity(player1, ENUM_MOB)->print();

	cout << endl;
	cout << "___________________________________________" << endl << endl;
	cout << endl;

	Environment::getInstance()->attackAllMobs(player1);
	Environment::getInstance()->printAllEntities();
	cout << endl;

	cout << endl;
	cout << "___________________________________________" << endl << endl;
	cout << endl;


	Environment::getInstance()->removeAt(2);
	Environment::getInstance()->removeAt(6);
	Environment::getInstance()->removeAt(10);

	Environment::getInstance()->printAllEntities();
	cout << endl;

	delete point1;
	Environment::releaseInstance();
	
	cin.get();
	return 0;
}