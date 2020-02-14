#include "DNScache.h"
using namespace std;

int main()
{		
	DNSRecord r1;
	DNSRecord r2("my ip", "23.85.67.456");	
	DNSRecord r3("your ip", "234.46.123.2");	
	DNSRecord r4(r2);
	r2 = r3;

	r1.print();
	r2.print();
	r3.print();
	r4.print();

	cout << endl;

	DNSCache c1;
	c1.print();
	cout << endl;

	cout << "After we add the DNSRecords: " << endl;
	c1.add(r1);
	c1.add(r2);
	c1.add(r3);
	c1.print();

	cout << endl;
	
	char* searchedIp = c1.lookup("your ip");
	if (searchedIp != nullptr)
	{
		cout << "The searched ip is:      " << searchedIp << endl;
	}

	cout << endl;

	c1.flush();
	c1.print();
	c1.add(r4);
	c1.print();	
	
	int x = 0;
	cin >> x;
	return 0;
}
