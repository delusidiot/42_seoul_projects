#ifndef DOG_HPP_
# define DOG_HPP_

# include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog(void);
	Dog(const Dog &src);
	~Dog(void);

	virtual void	makeSound(void) const;
};

#endif