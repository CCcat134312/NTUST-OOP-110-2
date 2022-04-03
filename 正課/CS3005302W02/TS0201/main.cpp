// Name: 林信佑
// Date: 2022/2/22 下午 04:00:27
// Last Update: 2022/2/22 下午 04:00:27
// Problem statement: Computes the average and standard deviation
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	for (double n; cin >> n;)
	{
		vector<double> nums(n);
		for (double& i : nums)
			cin >> i;

		double average = 0;
		for (double i : nums)
			average += i;
		average /= n;

		double sd = 0;	// standard deviation
		for (double i : nums)
			sd += (average - i) * (average - i);
		sd /= n;
		sd = sqrt(sd);

		cout << "Average:" << average
			<< "\tStandard deviation:" << sd
			<< '\n';
	}
	return 0;
}