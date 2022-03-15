#ifndef ANIMAL_HPP_
# define ANIMAL_HPP_

# include <iostream>
# include "Brain.hpp"

class Animal
{
protected:
	std::string type;
public:
	Animal(void);
	Animal(const std::string &type);
	Animal(const Animal &src);
	virtual ~Animal(void);

	virtual Animal		&operator=(const Animal &rhs);
	virtual void		makeSound(void) const;
	virtual Brain		*getBrain(void) const;
	const std::string	&getType(void) const;
};

std::ostream	&operator<<(std::ostream &os, const Animal &instance);

#endif