#include "MagicBox.h"
#include "Rational.h"

using namespace std;

void test_char()
{
	MagicBox<char> mboxChar;
	mboxChar.list();

	for (int i = 65; i < 85; i++)
	{
		mboxChar.insert(i);
	}
	mboxChar.list();

	for (int i = 0; i < 20; i++)
	{
		mboxChar.pop();
		mboxChar.list();
	}
}

void test_double()
{
	MagicBox<double> mboxDouble;
	mboxDouble.list();

	for (int i = 0; i < 15; i++)
	{
		mboxDouble.insert(i + 0.5);
	}
	mboxDouble.list();

	for (int i = 0; i < 15; i++)
	{
		mboxDouble.pop();
		mboxDouble.list();
	}
}

void test_rational()
{
	MagicBox<Rational> mboxRat;
	mboxRat.list();

	for (int i = 0; i < 15; i++)
	{
		Rational number(i, i + 1);
		mboxRat.insert(number);
	}
	mboxRat.list();

	for (int i = 0; i < 15; i++)
	{
		mboxRat.pop();
		mboxRat.list();
	}	
}

void test_int()
{
	MagicBox<int> mboxInt;
	mboxInt.list();

	for (int i = 0; i < 10; i++)
	{
		mboxInt.insert(i);
	}
	mboxInt.list();

	for (int i = 0; i < 10; i++)
	{
		mboxInt.pop();
		mboxInt.list();
	}
}

int main()
{
	srand(time(0));

	cout << "The counting of numbers starts from 0" << endl;

	test_int();
	//test_double();
	//test_char();
	//test_rational();	


	int x = 0;
	cin >> x;
	return 0;
}