#include "FragTrap.hpp"

FragTrap::FragTrap(void)
: ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	_initialEnergyPoints = _energyPoints;
	std::cout << "Default constructor for FragTrap called" << std::endl;
}

FragTrap::FragTrap(const std::string &name)
: ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	_initialEnergyPoints = _energyPoints;
	std::cout << "Name constructor for FragTrap called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
	std::cout << "Copy constructor for FragTrap called" << std::endl;
	*this = src;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Destructor for FragTrap called" << std::endl;
	return;
}

FragTrap &FragTrap::operator=(FragTrap const & rhs)
{
	std::cout << "Assignement operator called, but it doesn't work because I got lazy making accessors" << std::endl;
	std::cout << rhs << std::endl;
	return *this;
}

void FragTrap::highFivesGuys( void )
{
	std::cout << "Hey guys! Give me a high five!" << std::endl;
}
