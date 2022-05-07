// Name: 林信佑
// Date: 2022/5/6 上午 11:28:22
// Last Update: 2022/5/6 上午 11:28:22
// Problem statement: Class Inheritance
#include "Email.h"

Email::Email(std::string message, std::string sender, std::string recipient, std::string title) :Document(message)
{
	this->sender = sender;
	this->recipient = recipient;
	this->title = title;
}

Email& Email::operator=(const Email& email)
{
	this->text = email.text;
	this->sender = email.sender;
	this->recipient = email.recipient;
	this->title = email.title;
	return *this;
}

void Email::setTitle(std::string title)
{
	this->title = title;
}

void Email::setSender(std::string sender)
{
	this->sender = sender;
}

void Email::setRecipient(std::string recipient)
{
	this->recipient = recipient;
}

std::string Email::getTitle() const
{
	return title;
}

std::string Email::getSender() const
{
	return sender;
}

std::string Email::getRecipient() const
{
	return recipient;
}
