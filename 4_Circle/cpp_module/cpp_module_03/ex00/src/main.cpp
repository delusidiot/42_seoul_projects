#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap robert("Robert");

	robert.attack("Jack");
	robert.takeDamage(6);
	robert.beRepaired(4);
	robert.takeDamage(3);
	robert.beRepaired(8);
	robert.takeDamage(17);
}