// Name: ªL«H¦ö
// Date: February 17, 2022
// Last Update: February 17, 2022
// Problem statement: ComputeHMS
#include <iostream>
using namespace std;

int main()
{
	for (unsigned long long input; cin >> input;)	// init and get data until EOF
	{
		cout << input / 3600 << " hours ";			// hours
		input %= 3600;
		cout << input / 60 << " minutes and ";		// mins
		input %= 60;
		cout << input << " seconds\n";				// secs
	}
	return 0;
}