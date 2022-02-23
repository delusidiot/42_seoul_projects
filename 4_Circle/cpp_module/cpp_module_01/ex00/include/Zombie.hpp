#ifndef __ZOMBIE_HPP__
# define __ZOMBIE_HPP__

# include <iostream>

class Zombie
{
private:
	std::string _name;
public:
	Zombie(std::string const name);
	~Zombie(void);
	
	void announce(void) const;
	std::string getName() const;
};

Zombie* newZombie( std::string name );
void randomChump(std::string name);

#endif