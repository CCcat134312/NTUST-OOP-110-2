// Name: 林信佑
// Date: 2022/3/15 下午 03:41:29
// Last Update: 2022/3/15 下午 03:41:29
// Problem statement: Design Month Class
#include "Month.h"
#include <string>
#include <map>
#include <iostream>

using namespace std;
int MonthToInt(char first, char second, char third)
{
	string temp = "";
	temp += first;
	temp += second;
	temp += third;

	map<string, int> months;
	months["Jan"] = 1, months["Feb"] = 2, months["Mar"] = 3, months["Apr"] = 4;
	months["May"] = 5, months["Jun"] = 6, months["Jul"] = 7, months["Aug"] = 8;
	months["Sep"] = 9, months["Oct"] = 10, months["Nov"] = 11, months["Dec"] = 12;
	if (months.find(temp) == months.end())	// if input isn't a month name
		return 1;
	return months[temp];
}

Month::Month()
{
	month = 1;
}

Month::Month(char first, char second, char third)
{
	month = MonthToInt(first, second, third);
}

Month::Month(int monthInt)
{
	if (monthInt >= 1 && monthInt <= 12)
		month = monthInt;
	else
		month = 1;
}

Month::~Month()
{
}

void Month::inputInt()
{
	int input;
	cin >> input;
	if (input >= 1 && input <= 12)
		month = input;
	else
		month = 1;
}

void Month::inputStr()
{
	char first, second, third;
	cin >> first >> second >> third;
	month = MonthToInt(first, second, third);
}

void Month::outputInt()
{
	cout << month;
}

void Month::outputStr()
{
	string months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
						  "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	cout << months[month - 1];
}

Month Month::nextMonth()
{
	int nextMonth = month % 12 + 1;
	return Month(nextMonth);
}

