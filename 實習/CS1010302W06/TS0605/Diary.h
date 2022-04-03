// Name: 林信佑
// Date: 2022/3/24 下午 02:13:27
// Last Update: 2022/3/24 下午 02:13:27
// Problem statement: Observation Diary
#pragma once
#include <string>
#include <vector>

typedef struct
{
	std::string name;
	std::string content;
}Event;

typedef struct
{
	std::string dayName;
	std::vector<Event> eventList;
}DayLog;

class Diary
{
public:
	static std::vector<DayLog> mainLog;
	static std::string Date;
	static void NewDay(std::string Date);
	static void NewEvent(std::string, std::string);
};
