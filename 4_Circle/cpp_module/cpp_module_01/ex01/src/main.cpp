#include "Zombie.hpp"

int main(void)
{
	int numberOfZombies = 4;

	Zombie *zombies = zombieHorde(numberOfZombies, "Robert");
	for (int i = 0; i < numberOfZombies; i++)
		zombies[i].announce();
	delete[] zombies;
}