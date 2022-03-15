#ifndef B_HPP_
# define B_HPP_

# include <iostream>
# include "Base.hpp"

class B: public Base
{
public:
	B(void);
	B(const B &src);
	~B(void);

	B	&operator=(const B &rhs);
};

std::ostream	&operator<<(std::ostream &os, const B &instance);

#endif
