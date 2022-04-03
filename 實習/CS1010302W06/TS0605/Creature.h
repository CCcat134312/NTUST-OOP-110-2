// Name: 林信佑
// Date: 2022/3/24 下午 02:13:27
// Last Update: 2022/3/24 下午 02:13:27
// Problem statement: Observation Diary
#pragma once
#include <string>
#include <map>
#include <iostream>
#include <sstream>

#include "Diary.h"

class Creature
{
private:
	std::string name;
	std::map<std::string, int> bodyPart;
	std::string partIndex;
	int birthdayIndex;

	std::string generateMessage(int, int);
public:
	Creature(std::string);
	Creature(std::string, Creature);

	void PrintStatus() const;
	void PrintLog() const;

	Creature& operator[](std::string);
	void operator=(int);
	void operator+=(int);
	void operator-=(int);
};