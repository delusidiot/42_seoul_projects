#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 750

int	testMain(void)
{
	Array<int>			intArray;
	Array<std::string>	stringArray(10);
	Array<std::string>	otherStringArray;

	stringArray[0] = "Hi";
	stringArray[1] = "Hello";
	stringArray[2] = "How are you?";
	stringArray[3] = "Fine and you?";
	stringArray[4] = "Doing great thanks!";
	stringArray[5] = "You're very welcome";
	std::cout << "intArray.size() = " << intArray.getSize() << std::endl;
	std::cout << "stringArray.size() = " << stringArray.getSize() << std::endl << std::endl;
	otherStringArray = stringArray;
	otherStringArray[3] = "I'm good, how about you?";
    std::cout << "stringArray[3] = " << stringArray[3] << std::endl;
	std::cout << "otherStringArray[3] = " << otherStringArray[3] << std::endl;
    std::cout << "otherStringArray.size() = " << otherStringArray.getSize() << std::endl << std::endl;
    Array<std::string> anotherStringArray(stringArray);
    anotherStringArray[3] = "I'm fine.";
    std::cout << "stringArray[3] = " << stringArray[3] << std::endl;
	std::cout << "otherStringArray[3] = " << anotherStringArray[3] << std::endl;
    std::cout << "anotherStringArray.size() = " << anotherStringArray.getSize() << std::endl << std::endl;

	try
	{
		std::cout << stringArray[10] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << stringArray[-3] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}

int project_main(void)
{
	Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
	return 0;
}

int main(void)
{
    Array<int> a(0);
	std::cout << "module07 in main function" << std::endl;
	project_main();
	std::cout << std::endl;
	std::cout << "my test main function" << std::endl;
	testMain();
    return 0;
}
