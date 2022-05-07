// Name: 林信佑
// Date: 2022/5/6 上午 11:28:22
// Last Update: 2022/5/6 上午 11:28:22
// Problem statement: Class Inheritance
#pragma once
#include "Document.h"
class File :
    public Document
{
private:
    std::string pathname;
public:
    File(std::string, std::string);
    File& operator=(const File&);
    void setPathname(std::string);
    std::string getPathname() const;
};

