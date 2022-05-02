// Name: 林信佑
// Date: 2022/5/1 上午 12:20:20
// Last Update: 2022/5/1 上午 12:20:20
// Problem statement: Combinations
#include "PrintCombination.h"

void PrintCombination(int* arrPtr, int size, int choice)
{
	std::vector<bool> com(size, true);
	std::fill(com.begin() + choice, com.end(), false);
	std::vector<std::vector<int>> output;
	do
	{
		std::vector<int> temp;
		for (int i = 0; i < size ; i++)
		{
			if (com[i])
				temp.push_back(arrPtr[i]);
		}
		output.push_back(temp);	// save answer
	} while (std::prev_permutation(com.begin(), com.end()));	// list all combination
	for (const auto& v : output)
	{
		for (int i = 0; i < choice - 1; i++)
			std::cout << v[i] << ' ';
		std::cout << v[choice - 1] << '\n';
	}
}