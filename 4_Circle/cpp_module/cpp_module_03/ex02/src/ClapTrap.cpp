#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
: _name("Anonnymous"), _hitPoints(10), _energyPoints(10), _attackDamage(0), _initialEnergyPoints(_energyPoints)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name)
: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0), _initialEnergyPoints(_energyPoints)
{
	std::cout << "Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
	std::cout << "Assignement operator called." << std::endl;
	std::cout << rhs << std::endl;
	return *this;
}

std::ostream &operator<<(std::ostream &os, ClapTrap const & instance)
{
	os << "ClapTrap " << instance.getName();
	return os;
}

void ClapTrap::attack(std::string const &target) const
{
	std::cout << "ClapTrap " << this->getName() << " attack " << target	<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_energyPoints <= 0)
		std::cout << "ClapTrap " << this->getName() << " took " << amount << " damage and is quite unwell by now." << std::endl;
	else
	{
		if (this->_energyPoints < (int)amount)
			this->_energyPoints = 0;
		else
			this->_energyPoints -= amount;
		std::cout << "ClapTrap " << this->getName() << " took " << amount << " damage. " << this->_energyPoints	<< " energy points left." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	this->_energyPoints += amount;
	if (this->_energyPoints > this->_initialEnergyPoints)
	{
		this->_energyPoints = this->_initialEnergyPoints;
		std::cout << "You can't repaire more than your max!" << std::endl;
	}
	std::cout << "ClapTrap " << this->getName() << " energy has been charged by " << amount << ". now he's got " << this->_energyPoints << "." << std::endl;
}

const std::string &ClapTrap::getName(void) const
{
	return this->_name;
}