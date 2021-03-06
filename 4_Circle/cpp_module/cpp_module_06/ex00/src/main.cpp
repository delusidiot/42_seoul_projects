#include "TypeAnalyst.hpp"

void	print_usage(void)
{
	std::cout << "./convert {char, int, float or double}" << std::endl;
}

int	main(int argc, char **argv)
{
	TypeAnalyst typeAnalyst;

	try
	{
		if (argc == 1)
			throw (TypeAnalyst::EmptyInput());
		for (int i = 1; i < argc; i++)
		{
			typeAnalyst.analyseNewInput(argv[i]);
			typeAnalyst.printTypes();
			if (i + 1 < argc)
				std::cout << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		print_usage();
	}
}
