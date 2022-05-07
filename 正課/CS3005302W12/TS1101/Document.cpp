// Name: 林信佑
// Date: 2022/5/6 上午 11:28:22
// Last Update: 2022/5/6 上午 11:28:22
// Problem statement: Class Inheritance
#include "Document.h"

Document::Document(std::string text)
{
	this->text = text;
}

void Document::setText(std::string text)
{
	this->text = text;
}

std::string Document::getText() const
{
	return text;
}

Document& Document::operator=(const Document& doc)
{
	this->text = doc.text;
	return *this;
}
