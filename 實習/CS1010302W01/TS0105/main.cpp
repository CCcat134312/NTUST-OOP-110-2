// Name: ªL«H¦ö
// Date: February 17, 2022
// Last Update: February 17, 2022
// Problem statement: Compute Sphere Volume
#include <iostream>
#include <iomanip>
using namespace std;

double SphereVolume(double radius)
{
	double PI = 3.14159265358979323846;
	return 4.0 / 3.0 * PI * radius * radius * radius;
}
int main()
{
	for (double radius; cin >> radius; )	// init and get data until EOF
	{
		cout << fixed << setprecision(6) << SphereVolume(radius) << '\n';
	}
	return 0;
}