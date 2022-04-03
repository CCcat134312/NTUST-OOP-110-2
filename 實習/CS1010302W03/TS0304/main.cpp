// Name: 林信佑
// Date: 2022/3/3 下午 01:33:40
// Last Update: 2022/3/3 下午 01:33:40
// Problem statement: CPU bit growth
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	for (int input; cin >> input;)
	{
		int pows = (input - 1900) / 10;
		double bits = (1 << (pows + 2)); // 4 * 2 ^ (pows) => 2 ^ (pows + 2)

		long long cnt(1);
		for (double temp = 0; temp < bits; cnt++)
		{
			temp += log2(cnt);
		}
		cout << cnt - 2 << '\n';
	}
	return 0;
}