#include <iostream>

int main(void)
{
	std::string	originalString = "HI THIS IS BRAIN";
	std::string *stringPTR = &originalString;
	std::string	&stringREF = originalString;

	std::cout << "Original string address: " << &originalString << std::endl;
	std::cout << "using stringPTR address: " << &(*stringPTR) << std::endl;
	std::cout << "using stringREF address: " << &stringREF << std::endl;

	std::cout << "Original string: " << originalString << std::endl;
	std::cout << "using stringPTR: " << *stringPTR << std::endl;
	std::cout << "using stringREF: " << stringREF << std::endl;
}