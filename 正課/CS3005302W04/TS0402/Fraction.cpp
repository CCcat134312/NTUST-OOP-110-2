#include "Fraction.h"

int Fraction::getGCD(int a, int b)
{
	if (b == 0)
		return a;
	return getGCD(b, a % b);
}

void Fraction::setNumerator(int nu)
{
	numerator = nu;
}

void Fraction::setDenominator(int de)
{
	denominator = de;
}

void Fraction::getDouble()
{
	double output = (double)numerator / (double)denominator;
	if (output == (int)output)
		cout << fixed << setprecision(0) << output << '\n';
	else
		cout << fixed << setprecision(6) << output << "\n";
}

void Fraction::outputReducedFraction()
{
	if ((numerator >= denominator && numerator % denominator == 0) || numerator == 0 || denominator == 0)
	{
		cout << numerator / denominator << '\n';
		return;
	}
	int gcd = getGCD(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
	cout << numerator << "/" << denominator << '\n';
}



