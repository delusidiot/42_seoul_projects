#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main( void )
{
	{
		FragTrap frag("Frag");

		frag.attack("Jack");
		frag.takeDamage(6);
		frag.beRepaired(4);
		frag.takeDamage(3);
		frag.highFivesGuys();
		frag.beRepaired(8);
		frag.takeDamage(17);
	}
	{
		ScavTrap scav("Scav");

		scav.attack("Jack");
		scav.takeDamage(6);
		scav.beRepaired(4);
		scav.takeDamage(3);
		scav.guardGate();
		scav.beRepaired(8);
		scav.takeDamage(17);
	}
	{
		ClapTrap clap("Clap");

		clap.attack("Jack");
		clap.takeDamage(6);
		clap.beRepaired(4);
		clap.takeDamage(3);
		clap.beRepaired(8);
		clap.takeDamage(17);
	}
}
