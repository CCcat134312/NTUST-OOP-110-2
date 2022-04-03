// Name: 林信佑
// Date: 2022/3/17 下午 01:34:27
// Last Update: 2022/3/17 下午 01:34:27
// Problem statement: Student Records
#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef struct {
	char firstName[25];
	char lastName[30];
	char phone[15];
} StRec;

bool operator==(const StRec& a, const StRec& b)
{
	int firstNameSize = strlen(a.firstName);
	if (firstNameSize != strlen(b.firstName))
		return false;
	for (int i = 0; i < firstNameSize; i++)
	{
		if (a.firstName[i] != b.firstName[i])
			return false;
	}

	int lastNameSize = strlen(a.lastName);
	if (lastNameSize != strlen(b.lastName))
		return false;
	for (int i = 0; i < lastNameSize; i++)
	{
		if (a.lastName[i] != b.lastName[i])
			return false;
	}

	int phoneSize = strlen(a.phone);
	if (phoneSize != strlen(b.phone))
		return false;
	for (int i = 0; i < phoneSize; i++)
	{
		if (a.phone[i] != b.phone[i])
			return false;
	}
	return true;
}

ostream& operator<<(ostream& os, StRec s)
{
	os << s.firstName << ' ';
	os << s.lastName << ' ';
	os << s.phone;
	return os;
}

// read data and init object
int initStRec(StRec& target)
{
	string firstName, lastName, phone;
	cin >> firstName >> lastName >> phone;
	if (firstName.size() > 25 || lastName.size() > 30 || phone.size() > 15)
		return -1;	// input out of range
	for (char c : phone)	// phone number is not number
	{
		if (!(c >= '0' || c <= '9'))
			return -1;
	}

	// init char array
	memset(&target.firstName, '\0', sizeof(target.firstName));
	memset(&target.lastName, '\0', sizeof(target.lastName));
	memset(&target.phone, '\0', sizeof(target.phone));

	// copy input to char array
	for (int i = 0; i < firstName.size(); i++)
		target.firstName[i] = firstName[i];
	for (int i = 0; i < lastName.size(); i++)
		target.lastName[i] = lastName[i];
	for (int i = 0; i < phone.size(); i++)
		target.phone[i] = phone[i];
	return 0;	// no problem
}

int main()
{
	vector<StRec> students;
	for (string command; cin >> command;)
	{
		if (command == "print")
		{
			if (students.size() == 0)
			{
				cout << "Print Error\n";
				continue;
			}
			// output StRec datas
			for (StRec& s : students)
				cout << s << '\n';
		}
		else if (command == "search")
		{
			StRec input;
			if (initStRec(input) == -1)	// check input
			{
				cout << "Input Error\n";
				continue;
			}

			vector<StRec>::iterator target = find(students.begin(), students.end(), input);
			if (target != students.end())	// find record successfully
				cout << target - students.begin() << '\n';
			else // data not found
				cout << "Search Error\n";
		}
		else if (command == "insert")
		{
			StRec input;
			if (initStRec(input) == -1) // check input
			{
				cout << "Input Error\n";
				continue;
			}

			vector<StRec>::iterator target = find(students.begin(), students.end(), input);
			// already 10 records or data already in records
			if (students.size() >= 10 || target != students.end())
				cout << "Insert Error\n";
			else // new data -> insert
				students.push_back(input);
		}
		else if (command == "delete")
		{
			StRec input;
			if (initStRec(input) == -1) // check input
			{
				cout << "Input Error\n";
				continue;
			}

			auto target = find(students.begin(), students.end(), input);
			if (target != students.end())	// data in vector -> delete
				students.erase(target);
			else // not found
				cout << "Delete Error\n";
		}
		else
		{
			cout << "can't find \"" << command << "\"\n";
		}
	}
	return 0;
}