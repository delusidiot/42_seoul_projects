#ifndef BRAIN_HPP_
# define BRAIN_HPP_

# include <iostream>

class Brain
{
private:
	static const int	numberOfIdeas = 100;
public:
	Brain(void);
	Brain(const Brain &src);
	~Brain(void);
	Brain	&operator=(const Brain &rhs);

	std::string		ideas[Brain::numberOfIdeas];
};

#endif
