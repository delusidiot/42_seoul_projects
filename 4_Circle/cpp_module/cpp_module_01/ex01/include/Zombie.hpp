#ifndef __ZOMBIE_HPP__
# define __ZOMBIE_HPP__

# include <iostream>

class Zombie
{
private:
	std::string _name;
public:
	Zombie();
	Zombie(std::string const name);
	~Zombie(void);
	
	void announce(void) const;

	std::string getName() const;
	void setName(std::string name);
};

Zombie* zombieHorde(int numberOfZombies, std::string name);

#endif