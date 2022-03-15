#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
: type("")
{
	std::cout << "Default constructor for WrongAnimal called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type)
: type(type)
{
	std::cout << "Type constructor for WrongAnimal called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
	std::cout << "Copy constructor for WrongAnimal called" << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Destructor for WrongAnimal called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs)
{
	std::cout << "Assignement operator for WrongAnimal called" << std::endl;
	this->type = rhs.getType();
	return *this;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "Not a WrongAnimal!" << std::endl;
}

const std::string &WrongAnimal::getType(void) const
{
	return (this->type);
}

std::ostream &operator<<(std::ostream &os, const WrongAnimal &instance)
{
	os << instance.getType();;
	return os;
}