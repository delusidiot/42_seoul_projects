#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Form			*form = NULL;

	Bureaucrat		bob("bob", 1);
	Bureaucrat		phil("phil", 40);
	Bureaucrat		robert("robert", 150);

	form = new ShrubberyCreationForm("TreeGuard");
	try
	{
		form->beSigned(bob);
		form->execute(phil);
		form->execute(robert);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete form;
	form = NULL;
	form = new RobotomyRequestForm("RobotomyCooperation");
	try
	{
		form->beSigned(bob);
		form->execute(phil);
		form->execute(phil);
		form->execute(phil);
		form->execute(phil);
		form->execute(phil);
		form->execute(phil);
		form->execute(phil);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete form;
	form = new PresidentialPardonForm("sacred");
	try
	{
		form->execute(bob);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	delete form;
	form = new PresidentialPardonForm("holy");
	try
	{		
		form->beSigned(bob);
		form->execute(bob);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete form;
	return 0;
}
