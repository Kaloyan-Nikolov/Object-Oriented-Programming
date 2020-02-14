#include "Rational.h"

// Конструктор с 2 параметъра
Rational::Rational(int n, int d)
{
	if (n == 0 || d == 0) {
		numer = 0;
		denom = 1;
	}
	else {
		int g = gcd(abs(n), abs(d));
		if (n > 0 && d > 0 || n < 0 && d < 0) {
			numer = abs(n) / g;
			denom = abs(d) / g;
		}
		else {
			numer = -abs(n) / g;
			denom = abs(d) / g;
		}
	}
}

void Rational::setNumerator(int numer)
{
	this->numer = numer;
}

int Rational::getNumerator() const
{
	return numer;
}

void Rational::setDenominator(int denom)
{
	this->denom = denom;
}


int Rational::getDenominator() const
{
	return denom;
}

// Най-голям общ делител
int Rational::gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

ostream & operator<<(ostream & os, const Rational & r)
{
	if (r.getDenominator() != 1)
	{
		os << r.getNumerator() << "\\" << r.getDenominator();
	}
	else
	{
		os << r.getNumerator();
	}
	return os;
}