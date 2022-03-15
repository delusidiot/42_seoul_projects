#include "Animal.hpp"

Animal::Animal(void)
: type("")
{
	std::cout << "Default constructor for Animal called" << std::endl;
}

Animal::Animal(const std::string &type)
: type(type)
{
	std::cout << "Type constructor for Animal called" << std::endl;
}

Animal::Animal(Animal const & src)
{
	std::cout << "Copy constructor for Animal called" << std::endl;
	*this = src;
}

Animal::~Animal(void)
{
	std::cout << "Destructor for Animal called" << std::endl;
}

Animal &Animal::operator=(Animal const &rhs)
{
	std::cout << "Assignement operator for Animal called" << std::endl;
	this->type = rhs.getType();
	return *this;
}

void Animal::makeSound(void) const
{
	std::cout << "Not a Animal!" << std::endl;
}

const std::string &Animal::getType(void) const
{
	return (this->type);
}

std::ostream &operator<<(std::ostream &os, const Animal &instance)
{
	os << instance.getType();;
	return os;
}