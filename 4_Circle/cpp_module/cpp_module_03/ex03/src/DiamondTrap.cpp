#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
:ClapTrap("Anonymous_clap_name"), FragTrap(), ScavTrap(), _name("Anonymous")
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	_initialEnergyPoints = _energyPoints;
	std::cout << "Default constructor for DiamondTrap called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name)
:ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	_initialEnergyPoints = _energyPoints;
	std::cout << "Name constructor for DiamondTrap called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src)
:ClapTrap(src), FragTrap(src), ScavTrap(src)
{
	std::cout << "Copy constructor for DiamondTrap called" << std::endl;
	*this = src;
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "Destructor for DiamondTrap called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs)
{
	std::cout << "Assignement operator doesn't work, get lost" << std::endl;
	std::cout << rhs << std::endl;
	return *this;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void		DiamondTrap::whoAmI( void ) const
{
	std::cout << "I am " << this->_name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
