#include "Dog.hpp"

Dog::Dog(void)
: Animal("Dog")
{
	std::cout << "Default constructor for Dog called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog &src)
: Animal(src)
{
	std::cout << "Copy constructor for Dog called" << std::endl;
	*this = src;
}

Dog::~Dog(void)
{
	std::cout << "Destructor for Dog called" << std::endl;
	delete this->brain;
}

Dog &Dog::operator=(const Dog &rhs)
{
	std::cout << "Assignement operator for Cat called" << std::endl;
	this->type = rhs.getType();
	*(this->brain) = *(rhs.getBrain());
	return *this;
}

Animal &Dog::operator=(const Animal &rhs)
{
	std::cout << "Animal Assignement operator for Cat called" << std::endl;
	this->type = rhs.getType();
	*(this->brain) = *(rhs.getBrain());
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof!!" << std::endl;
}

Brain *Dog::getBrain(void) const
{
	return (this->brain);
}