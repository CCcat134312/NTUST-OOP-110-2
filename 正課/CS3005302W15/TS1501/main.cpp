// Name: ªL«H¦ö
// Date: 2022/5/24
// Last Update: 2022/5/24
// Problem statement: Set Exercise
#include <iostream>
#include <fstream>
#include <string>
#include <set>
using namespace std;

int main(void)
{
	ifstream fin("name.txt");
	set<string> names;
	for (string input; getline(fin, input);)
		names.insert(input);
	fin.close();
	for (auto& s : names)
		cout << s << '\n';
	return 0;
}