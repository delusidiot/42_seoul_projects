#ifndef DOG_HPP_
# define DOG_HPP_

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *brain;
public:
	Dog(void);
	Dog(const Dog &src);
	virtual ~Dog(void);

	Dog				&operator=(const Dog &rhs);
	virtual Animal	&operator=(const Animal &rhs);
	virtual void	makeSound(void) const;
	virtual Brain	*getBrain(void) const;
};

#endif