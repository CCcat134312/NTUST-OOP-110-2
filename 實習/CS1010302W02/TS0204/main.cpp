// Name: 林信佑
// Date: 2022/2/24 下午 03:49:10
// Last Update: 2022/2/24 下午 03:49:10
// Problem statement: Print Standard Format
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
struct Employee
{
	string name, salary, award;
};
int main()
{
	for (int numbers; cin >> numbers;)
	{
		vector<Employee> employees(numbers);
		int maxNameLength(0), maxSalaryLength(0), maxAwardLength(0);
		for (Employee& e : employees)
		{
			cin >> e.name >> e.salary >> e.award;

			//	update max length
			maxNameLength = max(maxNameLength, (int)e.name.size());
			maxSalaryLength = max(maxSalaryLength, (int)e.salary.size());
			maxAwardLength = max(maxAwardLength, (int)e.award.size());
		}

		cout.right;
		for (Employee e : employees)
		{
			//	set width
			cout << setw(maxNameLength) << e.name << '|';
			cout << setw(maxSalaryLength + 2) << e.salary << '|';
			cout << setw(maxAwardLength + 2) << e.award << '\n';
		}
	}
	return 0;
}