// Name: ªL«H¦ö
// Date: May 22, 2022
// Last Update: May 22, 2022
// Problem statement: School Inheritance
#pragma once
#include <iostream>
#include <string>

class School
{
protected:
	std::string name;
	float studentAmount;
	float studentAmountNextYear;
public:
	School() { name = "", studentAmount = 0, studentAmountNextYear = 0; };
	School(std::string name, float amount)
	{
		this->name = name;
		this->studentAmount = amount;
		this->studentAmountNextYear = amount;
	};
	virtual void admissions(float amount);
	virtual void dropouts(float amount);
	virtual void transfer(float amount, School& toSchool);

	friend std::ostream& operator<<(std::ostream& os, const School& school);
};

class PublicSchool :public School
{
protected:
	float growing_rate;
public:
	PublicSchool() :School() { growing_rate = 0.05; };
	PublicSchool(std::string name, float amount) :School(name, amount) { growing_rate = 0.05; };
	void apply_growth();
	virtual void dropouts(float amount) override;
};

class PrivateSchool :public School
{
protected:
	int dropoutTimes;
public:
	PrivateSchool() :School() { dropoutTimes = 0; };
	PrivateSchool(std::string name, float amount) :School(name, amount) { dropoutTimes = 0; };
	virtual void dropouts(float amount) override;
};