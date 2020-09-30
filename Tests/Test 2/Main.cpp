#include "Person.h"
#include "BankAccount.h"
#include "PersonWithAccount.h"

using namespace std;

int main()
{
	PersonWithAccount p1;
	p1.print();
	cout << endl;

	PersonWithAccount p2("Ivan Ivanov", "1234567890", 21, 1998, 1234, 321, "7418529630");
	p2.print();
	cout << endl;

	PersonWithAccount p3("Petar Petrov", "9876543210", 30, 1990, 2110, 1000, "5432169870");
	p3.print();
	cout << endl;

	PersonWithAccount p4;
	p4 = p3;
	p4.print();
	cout << endl;

	p4.regester();
	cout << endl;
	p4.print();
	cout << endl;

	p4.withdrawMoney(500);
	p4.print();

	return 0;
}