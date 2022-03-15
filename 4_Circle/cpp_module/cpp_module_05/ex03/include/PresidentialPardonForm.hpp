#ifndef PRESIDENTIALPARDONFORM_HPP_
# define PRESIDENTIALPARDONFORM_HPP_

# include <iostream>
# include "Form.hpp"
# include "Bureaucrat.hpp"

class PresidentialPardonForm : public Form
{
private:
	const std::string	_target;
	PresidentialPardonForm(void);
public:
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	virtual ~PresidentialPardonForm(void);

	PresidentialPardonForm	&operator=(const PresidentialPardonForm &rhs);

	const std::string	&getTarget(void) const;
	virtual void		execute(const Bureaucrat &executor) const;
};

/* std::ostream	&operator<<( std::ostream &ostr, const PresidentialPardonForm &instance ); */

#endif
