#ifndef CAT_HPP_
# define CAT_HPP_

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *brain;
public:
	Cat(void);
	Cat(const Cat &src);
	virtual ~Cat(void);

	Cat				&operator=(const Cat &rhs);
	virtual Animal	&operator=(const Animal &rhs);
	virtual void	makeSound(void) const;
	virtual Brain	*getBrain(void) const;
};

#endif