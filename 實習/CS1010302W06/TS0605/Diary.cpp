// Name: 林信佑
// Date: 2022/3/24 下午 02:13:27
// Last Update: 2022/3/24 下午 02:13:27
// Problem statement: Observation Diary
#include "Diary.h"

std::string Diary::Date = "";
std::vector<DayLog> Diary::mainLog;

void Diary::NewDay(std::string Date)
{
	Diary::Date = Date;
	DayLog newDay = { Date };
	mainLog.push_back(newDay);
}

void Diary::NewEvent(std::string name, std::string content)
{
	Event newEvent = { name,content };
	mainLog.back().eventList.push_back({ newEvent });
}