// Name: 林信佑
// Date: 2022/3/2 下午 10:04:31
// Last Update: 2022/3/2 下午 10:04:31
// Problem statement: Occurrenc Counting
#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<int, int, greater<int>> hash;
	for (int input; cin >> input; hash[input]++);	// input and store data to map

	cout << "N\tcount\n";
	for (auto i : hash)
		cout << i.first << '\t' << i.second << '\n';
	return 0;
}