#include "Cat.hpp"

Cat::Cat(void)
: Animal("Cat")
{
	std::cout << "Default constructor for Cat called" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(const Cat &src)
: Animal(src)
{
	std::cout << "Copy constructor for Cat called" << std::endl;
	*this = src;
}

Cat::~Cat(void)
{
	std::cout << "Destructor for Cat called" << std::endl;
	delete this->brain;
}

Cat &Cat::operator=(const Cat &rhs)
{
	std::cout << "Assignement operator for Cat called" << std::endl;
	this->type = rhs.getType();
	*(this->brain) = *(rhs.getBrain());
	return *this;
}

Animal &Cat::operator=(const Animal &rhs)
{
	std::cout << "Animal Assignement operator for Cat called" << std::endl;
	this->type = rhs.getType();
	*(this->brain) = *(rhs.getBrain());
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow~" << std::endl;
}

Brain *Cat::getBrain(void) const
{
	return (this->brain);
}