#include "Guest.h"
#include "User.h"
#include <ctime>
#include "PowerUser.h"
#include "VIP.h"
#include "Admin.h"

using namespace std;

void test_PowerUser()
{
	PowerUser p1("666.777.88.99", "Petar", "654321", "I am power user");
	p1.printDetails();
	cout << endl;

	User newUser1("12.34.56.78", "Warrior", "myPassword", "I am new");
	PowerUser newUser2("21.34.56.78", "Guardian", "elf", "I am old");		

	p1.receiveRep(newUser1);
	p1.receiveRep(newUser1);
	p1.receiveRep(newUser2);

	cout << endl << endl;
	p1.printDetails();
	cout << endl;

	PowerUser p2;
	p2 = p1;
	p2.printDetails();
}

void test_VIP()
{	
	VIP v1("100.200.50.85", "Magician", "flying", "I am VIP");
	v1.printDetails();
	cout << endl;
	v1.changeTitle("now I am magician");
	v1.printDetails();
	cout << endl;
	v1.changePassword("flying", "swimming");
	v1.printDetails();
	cout << endl;
	v1.changePassword("sky", "jump");
	cout << endl;
	v1.printDetails();
	cout << endl;	
}

void test_Admin()
{	
	Admin a1("223.456.77.80", "Wizard", "magical_Word1", "I am the king");
	a1.printDetails();
	cout << endl;
	a1.changeUsername("Dragon");
	cout << endl;
	a1.printDetails();
	cout << endl;

	User u1("555.666.77.88", "Ivan", "4321", "I am an engineeer");
	PowerUser p1("666.777.88.99", "Petar", "654321", "I am power user");
	VIP v1("100.200.50.85", "Magician", "flying", "I am VIP");	

	a1.changeAnoherUsername(u1, "Flame");
	cout << endl;
	a1.changeAnoherUsername(p1, "Powerful");
	cout << endl;
	a1.changeAnoherUsername(v1, "Friend");
	cout << endl;

	u1.printDetails();
	cout << endl;
	p1.printDetails();
	cout << endl;
	v1.printDetails();
	cout << endl;

	a1.receiveRep(u1);
	cout << endl;
	a1.receiveRep(v1);
	cout << endl;
	a1.receiveRep(p1);
	cout << endl;

	a1.printDetails();
	cout << endl;

	a1.receiveRep(u1);
	cout << endl;
	a1.receiveRep(v1);
	cout << endl;
	a1.receiveRep(p1);
	cout << endl;

	Admin a2;
	a2 = a1;
	a2.printDetails();
	
}

int main()
{
	srand(time(0));	
	
	Guest g1("444.555.66.77");
	g1.printDetails();
	cout << endl;

	User u1("555.666.77.88", "Ivan", "abcd", "I am an engineeer");
	u1.printDetails();
	cout << endl;

	u1.changePassword("abcd", "9876");
	cout << endl;
	u1.printDetails();
	cout << endl;

	User u2;
	u2 = u1;
	u2.printDetails();

	//test_PowerUser();
	//test_VIP();
	//test_Admin();

	int x = 0;
	cin >> x;
	return 0;
}