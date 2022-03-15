#ifndef C_HPP_
# define C_HPP_

# include <iostream>
# include "Base.hpp"

class C: public Base
{
public:
	C(void);
	C(const C &src);
	~C(void);

	C	&operator=( const C &rhs );
};

std::ostream	&operator<<(std::ostream &os, const C &instance);

#endif
