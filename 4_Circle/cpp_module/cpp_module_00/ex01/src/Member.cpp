#include "Member.hpp"

Member::Member()
	:_firstName(""), _lastName(""), _nickName(""), _phoneNumber(""), _darkestSecret("")
{
}

void Member::setFirstName(const std::string str)
{
	this->_firstName = str;
}

void Member::setLastName(const std::string str)
{
	this->_lastName = str;
}

void Member::setPhoneNumber(const std::string str)
{
	this->_nickName = str;
}

void Member::setNickName(const std::string str)
{
	this->_phoneNumber = str;
}

void Member::setDarkestSecret(const std::string str)
{
	this->_darkestSecret = str;
}

std::string Member::getFirstName(void) const
{
	return this->_firstName;
}

std::string Member::getLastName(void) const
{
	return this->_lastName;
}

std::string Member::getNickName(void) const
{
	return this->_nickName;
}

std::string Member::getPhoneNumber(void) const
{
	return this->_phoneNumber;
}

std::string Member::getDarkestSecret(void) const
{
	return this->_darkestSecret;
}