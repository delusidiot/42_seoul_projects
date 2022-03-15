#ifndef SHRUBBERYCREATIONFORM_HPP_
# define SHRUBBERYCREATIONFORM_HPP_

# include <iostream>
# include "Form.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm : public Form
{
private:
	const std::string	_target;
	ShrubberyCreationForm(void);
public:
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	virtual ~ShrubberyCreationForm(void);

	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &rhs);

	const std::string	&getTarget(void) const;
	virtual void		execute(const Bureaucrat &executor) const;
};

/* std::ostream	&operator<<( std::ostream &ostr, const ShrubberyCreationForm &instance ); */

#endif
