#include "WrongCat.hpp"

WrongCat::WrongCat(void)
: WrongAnimal("WrongCat")
{
	std::cout << "Default constructor for WrongCat called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &src)
: WrongAnimal(src)
{
	std::cout << "Copy constructor for WrongCat called" << std::endl;
	*this = src;
}

WrongCat::~WrongCat(void)
{
	std::cout << "Destructor for WrongCat called" << std::endl;
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "Meow~" << std::endl;
}
