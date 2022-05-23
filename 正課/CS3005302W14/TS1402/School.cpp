// Name: ªL«H¦ö
// Date: May 22, 2022
// Last Update: May 22, 2022
// Problem statement: School Inheritance
#include "School.h"

void School::admissions(float amount)
{
	if (amount <= 0)
		return;
	studentAmount += amount;
}

void School::dropouts(float amount)
{
	if (amount <= 0)
		return;
	else if (amount > studentAmount)
		return;
	studentAmount -= amount;
}

void School::transfer(float amount, School& toSchool)
{
	if (amount <= 0)
		return;
	else if (amount > studentAmount)
		return;
	dropouts(amount);
	toSchool.admissions(amount);
}

std::ostream& operator<<(std::ostream& os, const School& school)
{
	os << school.name << "\t";
	os << school.studentAmount << "\t";
	os << school.studentAmountNextYear;
	return os;
}

void PublicSchool::apply_growth()
{
	studentAmountNextYear += growing_rate * studentAmountNextYear;
}

void PublicSchool::dropouts(float amount)
{
	if (amount <= 0)
		return;
	else if (amount > studentAmount)
		return;
	studentAmount -= amount;
	if (amount > 100)
		studentAmountNextYear = (int)(0.95 * studentAmountNextYear);
}

void PrivateSchool::dropouts(float amount)
{
	if (amount <= 0)
		return;
	else if (amount > studentAmount)
		return;
	studentAmount -= amount;
	if (dropoutTimes > 0)
		studentAmountNextYear -= 100;
	dropoutTimes++;
}
