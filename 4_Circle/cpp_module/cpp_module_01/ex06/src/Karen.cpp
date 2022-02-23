#include <iostream>
#include "Karen.hpp"

Karen::Karen(void)
{
}

Karen::Karen(Karen::logLevel level)
	:_level(level)
{
}

Karen::Karen(std::string level)
{
	this->_level = this->getLogLevelFromString(level);
}

Karen::~Karen(void)
{
}

Karen::logLevel Karen::getLogLevelFromString(std::string level)
{
	for (size_t i = 0; i < level.length(); i++)
		level[i] = toupper(level[i]);
	if (level == "DEBUG")
		return Karen::DEBUG;
	if (level == "INFO")
		return Karen::INFO;
	if (level == "WARNING")
		return Karen::WARNING;
	if (level == "ERROR")
		return Karen::ERROR;
	return Karen::NONE;
}

void Karen::complain(std::string level)
{
	this->complain(this->getLogLevelFromString(level));
}

void Karen::complain(void)
{
	this->complain(this->_level);
}

void Karen::complain(Karen::logLevel level)
{
	if (level == Karen::NONE)
	{
		this->defaultMessage();
		return ;
	}
	void (Karen::*complaint[])( void ) = {
		&Karen::debug,
		&Karen::info,
		&Karen::warning,
		&Karen::error
	};
	for (int i = level; i <= Karen::ERROR; i++)
	{
		void (Karen::*selectedComplaint)( void ) = complaint[i];
		(this->*selectedComplaint)();
	}
}

void	Karen::defaultMessage(void)
{
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl << std::endl;
}

void Karen::debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl << std::endl;
}

void Karen::info(void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl << std::endl;
}

void Karen::warning(void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free."
		<< "I’ve been coming here for years an you just started working here last month." << std::endl << std::endl;
}

void Karen::error(void)
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl << std::endl;
}

Karen::logLevel Karen::getLogLevel(void) const
{
	return this->_level;
}

bool Karen::setLogLevel(const logLevel level)
{
	this->_level = level;
	return true;
}
