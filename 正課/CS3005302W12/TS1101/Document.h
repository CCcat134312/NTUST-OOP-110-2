// Name: 林信佑
// Date: 2022/5/6 上午 11:28:22
// Last Update: 2022/5/6 上午 11:28:22
// Problem statement: Class Inheritance
#pragma once
#include <string>
class Document
{
protected:
	std::string text;
public:
	Document(std::string);
	void setText(std::string);
	std::string getText() const;
	Document& operator=(const Document&);
};

