// Name: ªL«H¦ö
// Date: February 17, 2022
// Last Update: February 17, 2022
// Problem statement: Input/Output 1
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	for (string input; cin >> input; )	// init and get data until EOF
	{
		cout << right << setw(10) << input << '\n';
	}
	return 0;
}