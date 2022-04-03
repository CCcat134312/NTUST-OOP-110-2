// Name: 林信佑
// Date: 2022/3/24 下午 02:13:27
// Last Update: 2022/3/24 下午 02:13:27
// Problem statement: Observation Diary
#include "Creature.h"

Creature::Creature(std::string name)
{
	this->name = name;
	birthdayIndex = Diary::mainLog.size() - 1;
}

Creature::Creature(std::string name, Creature base)
{
	this->name = name;
	// copy body part from base
	for (const auto& part : base.bodyPart)
		this->bodyPart[part.first] = part.second;
	birthdayIndex = Diary::mainLog.size() - 1;
}

void Creature::PrintStatus() const
{
	std::cout << name << "'s status:\n";
	for (const auto& part : bodyPart)
	{
		if (part.second != 0)
			std::cout << part.first << " * " << part.second << '\n';
	}
	std::cout << '\n';
}

void Creature::PrintLog() const
{
	std::cout << name << "'s log:\n";
	for (int i = birthdayIndex; i < Diary::mainLog.size(); i++)
	{
		std::cout << "Day " << Diary::mainLog[i].dayName << '\n';
		for (Event e : Diary::mainLog[i].eventList)
		{
			if (e.name == name)
				std::cout << e.content;
		}
	}
	std::cout << '\n';
}

Creature& Creature::operator[](std::string key)
{
	partIndex = key;
	// part not exist
	if (bodyPart.find(key) == bodyPart.end())
		bodyPart[key] = 0;
	return *this;
}

void Creature::operator=(int number)
{
	int old = bodyPart[partIndex];
	bodyPart[partIndex] = number;

	std::string record = generateMessage(old, bodyPart[partIndex]);
	if (record.size() == 0)
		return;
	Diary::NewEvent(name, record);
}

void Creature::operator+=(int number)
{
	int old = bodyPart[partIndex];
	bodyPart[partIndex] += number;

	std::string record = generateMessage(old, bodyPart[partIndex]);
	if (record.size() == 0)
		return;
	Diary::NewEvent(name, record);
}

void Creature::operator-=(int number)
{
	int old = bodyPart[partIndex];
	bodyPart[partIndex] -= number;

	std::string record = generateMessage(old, bodyPart[partIndex]);
	if (record.size() == 0)
		return;
	Diary::NewEvent(name, record);
}

std::string Creature::generateMessage(int old, int now)
{
	// compare old and new number
	std::stringstream ss;
	ss << name << "'s " << partIndex << ' ';
	if (old == 0 && now > 0)
		ss << "appeared ";
	else if (old > now)
		ss << "decreased ";
	else if (old < now)
		ss << "increased ";
	else if (old == now)
		return "";
	ss << '(' << old << " -> " << now << ").\n";
	return ss.str();
}