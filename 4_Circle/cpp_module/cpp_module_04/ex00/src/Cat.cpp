#include "Cat.hpp"

Cat::Cat(void)
: Animal("Cat")
{
	std::cout << "Default constructor for Cat called" << std::endl;
}

Cat::Cat(Cat const &src)
: Animal(src)
{
	std::cout << "Copy constructor for Cat called" << std::endl;
	*this = src;
}

Cat::~Cat(void)
{
	std::cout << "Destructor for Cat called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow~" << std::endl;
}