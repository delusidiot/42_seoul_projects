#include "Replace.hpp"
#include <iostream>

int usage(void)
{
	std::cout << "./replace fileName stringToReplace replacement." << std::endl;
	return 1;
}

int putError(std::string msg)
{
	std::cerr << "Error: " << msg << std::endl;
	return 1;
}

int main(int argc, char **argv)
{
	Replace replace;

	if (argc != 4)
		return (usage());
	if (!replace.setFile(argv[1]))
		return (putError("Unable to open file."));
	if (!replace.replace(argv[2], argv[3]))
		return (putError("Strings can't be empty"));
	return 0;
}