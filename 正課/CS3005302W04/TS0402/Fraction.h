#ifndef Fraction_H
#define Fraction_H
#include <iostream>
#include <iomanip>
using namespace std;

class Fraction
{
private:
	int numerator;
	int denominator;
public:
	void setNumerator(int nu);
	void setDenominator(int de);
	void getDouble();
	void outputReducedFraction();
	int getGCD(int, int);

};

#endif //Fraction_H