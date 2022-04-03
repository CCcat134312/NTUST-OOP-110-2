// Name: 林信佑
// Date: 2022/2/22 下午 04:01:17
// Last Update: 2022/2/22 下午 04:01:17
// Problem statement: Leaderboard
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#define MAX 3
using namespace std;

struct Student
{
	string name;
	int score;
};

void getHighScore(vector<string> names, vector<int> scores)
{
	// create student vector to bind name and score
	int size = names.size();
	vector<Student> students(size);
	for (int i = 0; i < size; i++)
	{
		students[i].name = names[i];
		students[i].score = scores[i];
	}

	// sort by score
	auto rule = [](Student a, Student b) {return a.score > b.score; };
	sort(students.begin(), students.end(), rule);

	// output the student info
	for (int i = 0; i < MAX; i++)
		cout << students[i].name << '\n' << students[i].score << '\n';
}

int main()
{
	ifstream fin("scores.txt");
	if (!fin)	// exception handler
	{
		cout << "ERROR\n";
		exit(0);
	}

	vector<string> studentNames;
	vector<int> studentScores;
	for (Student input; fin >> input.name >> input.score;)	// get data from file until EOF
	{
		studentNames.push_back(input.name);
		studentScores.push_back(input.score);
	}
	fin.close();	// close file

	getHighScore(studentNames, studentScores);
	return 0;
}