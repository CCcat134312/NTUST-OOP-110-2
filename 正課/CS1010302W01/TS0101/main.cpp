// Name: ªL«H¦ö
// Date: February 17, 2022
// Last Update: February 17, 2022
// Problem statement: Compute the square root
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	for (double input; cin >> input;)	// init and get data until EOF
	{
		double guess = input / 2, temp;
		do
		{
			temp = guess;
			guess = (guess + input / guess) / 2;
		} while (abs(guess - temp) > 0.01);
		cout << fixed << setprecision(2) << guess << '\n';
	}
	return 0;
}