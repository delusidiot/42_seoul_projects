#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat robert = Bureaucrat("Robert", 1);
		std::cout << robert << std::endl;
		robert.decrementGrade(1);
		std::cout << robert << std::endl;
		robert.incrementGrade(1);
		std::cout << robert << std::endl;
		robert.incrementGrade(1);
		std::cout << robert << std::endl;
		robert.decrementGrade(1);
		std::cout << robert << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat jack = Bureaucrat("Jack", 150);
		std::cout << jack << std::endl;
		jack.incrementGrade(1);
		std::cout << jack << std::endl;
		jack.decrementGrade(1);
		std::cout << jack << std::endl;
		jack.decrementGrade(1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat john = Bureaucrat("John", 0);
		std::cout << john << std::endl;
		john.decrementGrade(1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	try
	{
		Bureaucrat mark = Bureaucrat("Mark", 151);
		std::cout << mark << std::endl;
		mark.incrementGrade(1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
