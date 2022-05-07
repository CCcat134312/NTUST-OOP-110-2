// Name: �L�H��
// Date: 2022/5/6 �W�� 11:28:22
// Last Update: 2022/5/6 �W�� 11:28:22
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

