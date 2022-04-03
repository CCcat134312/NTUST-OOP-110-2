// Name: 林信佑
// Date: 2022/3/22 下午 04:20:55
// Last Update: 2022/3/22 下午 04:20:55
// Problem statement: Number Game
#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
class NumberGame
{
private:
	std::string inputNumber;
	std::string fileName;
	std::set<int> allCombination;
	std::vector<int> validNumber;
public:
	NumberGame();
	void SetInput(int);
	void ProcessInput();
	void SetFileName(std::string);
	void LoadNumberList();
	void PrintAllValid();
	void Reset();
};
