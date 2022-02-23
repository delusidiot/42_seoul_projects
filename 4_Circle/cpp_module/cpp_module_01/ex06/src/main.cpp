#include "Karen.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "./karen logLevel." << std::endl;
		return 1;
	}
	std::string level(argv[1]);
	Karen karen(level);

	karen.complain();
	return 0;
}