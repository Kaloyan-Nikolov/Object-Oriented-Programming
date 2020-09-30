#include "Browser.h"

int main()
{
	WebPage wp1, wp2, wp3;
	cout << "Enter first webpage:" << endl;
	cin >> wp1;
	cout << "Enter second webpage:" << endl;
	cin >> wp2;

	wp3.setAddress("https://www.fmi.uni-sofia.bg");
	wp3.setIpAddress("56.78.901.12");

	cout << endl;
	cout << wp1 << wp2 << wp3 << endl;

	Browser br;
	br += wp1;
	br += wp2;
	br += wp3;

	cout << endl;

	cout << "Pages in browser 1:" << endl;
	br.print();

	cout << endl;

	Browser br2;
	br2 = br;

	cout << "Pages in browser 2:" << endl;

	br2.print();
	br2 -= 2;

	cout << endl;

	cout << "Pages in browser 2 after we removed 2nd page:" << endl;
	br2.print();

	return 0;
}