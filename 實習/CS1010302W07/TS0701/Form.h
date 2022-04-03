// Problem statement: Form Word
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class Form
{
private:
	std::vector<int> letters;
	std::string inputWord;
	std::string fileName;
	std::vector<std::string> foundWords;

	std::vector<int> CountLetters(std::string);	// count every letters appear times
public:
	Form();
	void SetInputWord(std::string inputWord); // set input
	void ProcessInputWord(); // process input
	void SetFileName(std::string fileName); // set file name
	void Load_CompareWord(); // read-in data and compare
	void PrintFoundWords(); // print answers
};
