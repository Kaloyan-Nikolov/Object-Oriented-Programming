#pragma once
#include <iostream>
using namespace std;

class Rational {
private:
	int numer, denom;
	int gcd(int, int);

public:	
	Rational(int = 0, int = 1);
	
	void setNumerator(int numer);
	int getNumerator() const;
	void setDenominator(int denom);
	int getDenominator() const;

	friend ostream& operator<<(ostream& os, const Rational &r);
};
