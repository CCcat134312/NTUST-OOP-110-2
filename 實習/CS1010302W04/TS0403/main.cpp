// Name: 林信佑
// Date: 2022/3/10 下午 01:22:02
// Last Update: 2022/3/10 下午 01:22:02
// Problem statement: Common Divisor
#include <iostream>
using namespace std;

int GCD(int a, int b)
{
	if (b == 0)
		return a;
	return GCD(b, a % b);
}
int main()
{
	for (int a, b; cin >> a >> b;)
		cout << GCD(a, b) << '\n';
	return 0;
}