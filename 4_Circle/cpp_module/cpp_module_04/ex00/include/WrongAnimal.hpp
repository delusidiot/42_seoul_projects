#ifndef WRONGANIMAL_HPP_
# define WRONGANIMAL_HPP_

# include <iostream>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal(void);
	WrongAnimal(const std::string &type);
	WrongAnimal(const WrongAnimal &src);
	virtual ~WrongAnimal(void);

	WrongAnimal	&operator=(const WrongAnimal &other);
	void		makeSound(void) const;
	const std::string	&getType(void) const;
};

std::ostream	&operator<<(std::ostream &os, const WrongAnimal &instance);

#endif