#include "Dog.hpp"

Dog::Dog(void)
: Animal("Dog")
{
	std::cout << "Default constructor for Dog called" << std::endl;
}

Dog::Dog(Dog const &src)
: Animal(src)
{
	std::cout << "Copy constructor for Dog called" << std::endl;
	*this = src;
}

Dog::~Dog(void)
{
	std::cout << "Destructor for Dog called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof!!" << std::endl;
}