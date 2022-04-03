// Name: 林信佑
// Date: 2022/3/2 下午 10:06:31
// Last Update: 2022/3/2 下午 10:06:31
// Problem statement: Text-based histogram
#include <iostream>
#include <fstream>
#include <vector>
#define RANGE 5
using namespace std;

int main()
{
	vector<int> table(RANGE + 1, 0);
	ifstream fin("grade.txt");
	for (int input; fin >> input; table[input]++);	// get data and store to vector
	fin.close();

	ofstream fout("grades.Output", ios::out);
	for (int i = 0; i < RANGE + 1; i++)
		fout << table[i] << " grade(s) of " << i << '\n';
	fout.close();
	return 0;
}