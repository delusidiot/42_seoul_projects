#include "Zombie.hpp"

int main(void)
{
	Zombie robert("Robert");
	robert.announce();

	Zombie *mark = newZombie("Mark");
	delete mark;

	randomChump("Mora");
}