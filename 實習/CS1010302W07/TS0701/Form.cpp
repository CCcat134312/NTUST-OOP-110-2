// Name: 林信佑
// Date: 2022/3/31 下午 02:58:24
// Last Update: 2022/3/31 下午 02:58:24
// Problem statement: Form Word
#include "Form.h"

Form::Form()
{
	letters = {};
	inputWord = "";
	fileName = "";
	foundWords = {};
}

void Form::SetInputWord(std::string inputWord)
{
	this->inputWord = inputWord;
}

void Form::ProcessInputWord()
{
	letters = CountLetters(inputWord);
}

void Form::SetFileName(std::string fileName)
{
	this->fileName = fileName;
}

void Form::Load_CompareWord()
{
	std::ifstream fin("words.txt");
	for (std::string input; fin >> input;)
	{
		auto readLetters = CountLetters(input);

		bool flag = true;
		for (int i = 0; i < 26; i++)
		{
			// if class word can't combine to fin's word
			if (readLetters[i] > 0 && readLetters[i] > letters[i])
				flag = false;
		}
		if (flag)
			foundWords.push_back(input);
	}
	fin.close();
}

void Form::PrintFoundWords()
{
	for (const auto& s : foundWords)
		std::cout << s << '\n';
}

std::vector<int> Form::CountLetters(std::string input)
{
	std::vector<int> result(26, 0);
	for (const auto& c : input)
	{
		int index = (int)(tolower(c) - 'a');
		result[index]++;
	}
	return result;
}