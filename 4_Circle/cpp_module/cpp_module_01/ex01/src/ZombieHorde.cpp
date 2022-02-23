#include "Zombie.hpp"

Zombie* zombieHorde(int numberOfZombies, std::string name)
{
	Zombie* zombieHorde = new Zombie[numberOfZombies];

	for (int i = 0; i < numberOfZombies; i++)
		zombieHorde[i].setName(name);
	return zombieHorde;
}