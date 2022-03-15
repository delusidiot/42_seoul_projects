#ifndef ROBOTOMYREQUESTFORM_HPP_
# define ROBOTOMYREQUESTFORM_HPP_

# include <iostream>
# include "Form.hpp"
# include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form
{
private:
	const std::string		_target;
	RobotomyRequestForm(void);
public:
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	virtual ~RobotomyRequestForm(void);

	RobotomyRequestForm	&operator=(const RobotomyRequestForm &rhs);

	const std::string	&getTarget(void) const;
	virtual void		execute(const Bureaucrat &executor) const;
};

/* std::ostream	&operator<<( std::ostream &ostr, const RobotomyRequestForm &instance ); */

#endif
