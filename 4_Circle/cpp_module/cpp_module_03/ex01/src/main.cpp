#include "ScavTrap.hpp"

int	main( void )
{
	{
		ScavTrap robert("Robert");

		robert.attack("Jack");
		robert.takeDamage(6);
		robert.beRepaired(4);
		robert.takeDamage(3);
		robert.guardGate();
		robert.beRepaired(8);
		robert.takeDamage(17);
	}
	{
		ClapTrap mora("mora");

		mora.attack("Jack");
		mora.takeDamage(6);
		mora.beRepaired(4);
		mora.takeDamage(3);
		mora.beRepaired(8);
		mora.takeDamage(17);
	}
	{
		ClapTrap *robert = new ScavTrap("Robert");
		delete(robert);
	}
}
