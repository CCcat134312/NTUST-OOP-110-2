// Name: 林信佑
// Date: 2022/2/24 下午 03:50:57
// Last Update: 2022/2/24 下午 03:50:57
// Problem statement: Compute The Tax
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	for (double input; cin >> input;)
	{
		double tax;
		if (input < 750)	// below 750
		{
			tax = input / 100.0;
		}
		else if (input < 2250)	// 750 ~ 2250
		{
			tax = 7.5;
			tax += (input - 750) / 100.0 * 2.0;
		}
		else if (input < 3750)	// 2250 ~ 3750
		{
			tax = 37.5;
			tax += (input - 2250) / 100.0 * 3.0;
		}
		else if (input < 5250)	// 3750 ~ 5250
		{
			tax = 82.5;
			tax += (input - 3750) / 100.0 * 4.0;
		}
		else if (input < 7000)	// 5250 ~ 7000
		{
			tax = 142.5;
			tax += (input - 5250) / 100.0 * 5.0;
		}
		else // over 7000
		{
			tax = 230.0;
			tax += (input - 7000) / 100.0 * 6.0;
		}
		cout << fixed << setprecision(2) << tax << '\n';
	}
	return 0;
}