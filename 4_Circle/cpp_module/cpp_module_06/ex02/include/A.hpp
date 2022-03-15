#ifndef A_HPP_
# define A_HPP_

# include <iostream>
# include "Base.hpp"

class A: public Base
{
public:
	A(void);
	A(const A &src);
	~A(void);

	A	&operator=( const A &rhs );
};

std::ostream	&operator<<(std::ostream &os, const A &instance);

#endif
