// Name: 林信佑
// Date: 2022/5/6 上午 11:28:22
// Last Update: 2022/5/6 上午 11:28:22
// Problem statement: Class Inheritance
#include "File.h"

File::File(std::string text, std::string pathname):Document(text)
{
	this->pathname = pathname;
}

File& File::operator=(const File& file)
{
	this->text = file.text;
	this->pathname = file.pathname;
	return *this;
}

void File::setPathname(std::string pathname)
{
	this->pathname = pathname;
}

std::string File::getPathname() const
{
	return pathname;
}
