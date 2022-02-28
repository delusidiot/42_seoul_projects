#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string name)
: ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_initialEnergyPoints = _energyPoints;
	std::cout << "Name constructor for ScavTrap called." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &rhs) : ClapTrap(rhs)
{
	std::cout << "Copy constructor for ScavTrap called" << std::endl;
	*this = rhs;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Destructor for ScavTrap called." << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
	std::cout << "Assignement operator called, but it doesn't work because I got lazy making accessors" << std::endl;
	std::cout << rhs << std::endl;
	return *this;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->getName() << " entered Gate Keeper mode."<< std::endl;
}

void ScavTrap::attack(std::string const &target) const
{
	std::cout << "ScavTrap " << this->getName() << " attack " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}