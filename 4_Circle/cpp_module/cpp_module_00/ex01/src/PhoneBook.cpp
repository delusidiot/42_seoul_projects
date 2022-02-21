#include "PhoneBook.hpp"
# include <iostream>
# include <string>
# include <iomanip>
# include <sstream>

PhoneBook::PhoneBook()
{
	this->index = 0;
}

void PhoneBook::printAllPhoneBook(void) const
{
	int curr = (index > MAX_INDEX)? MAX_INDEX : index;

	for (int i = 0; i < curr; i++)
		printDetailPhoneBook(i);
}

void PhoneBook::printDetailPhoneBook(const int index) const
{
	if (index >= this->index)
		std::cout << "This index hasn't been entered yet." << std::endl;
	else
	{
		std::cout << "|   " << (index + 1) << "   |";
		printFormat(members[index].getFirstName());
		std::cout << "|";
		printFormat(members[index].getLastName());
		std::cout << "|";
		printFormat(members[index].getNickName());
		std::cout << "|" << std::endl;
		std::cout<< "------------------------------------------" <<std::endl;
	}
}

void PhoneBook::printFormat(std::string str) const
{
	if (str.length() > 10)
	{
		str.insert(9, ".");
		str = str.substr(0, 10);
	}
	std::cout << std::setw(10) << str;
}

void PhoneBook::addPhoneBook(void)
{
	std::string str;
	int curr = index % MAX_INDEX;

	std::cout << "fist-name :";
	std::getline(std::cin, str);
	members[curr].setFirstName(str);
	std::cout << "last-name :";
	std::getline(std::cin, str);
	members[curr].setLastName(str);
	std::cout << "nick-name :";
	std::getline(std::cin, str);
	members[curr].setNickName(str);
	std::cout << "phone-number :";
	std::getline(std::cin, str);
	members[curr].setPhoneNumber(str);
	std::cout << "secret :";
	std::getline(std::cin, str);
	members[curr].setDarkestSecret(str);
	std::cout << "ADD Done" << std::endl;
	index++;
}

void PhoneBook::printPhoneBook(void) const
{
	std::string str;
	int idx;

	std::cout << "Enter 1 ~ 8. The rest will all index be printed." << std::endl;
	std::cout << "index: ";
	std::getline(std::cin, str);
	std::stringstream ssInt(str);
	ssInt >> idx;
	std::cout<< "==========================================" <<std::endl;
	std::cout<< "| Index | Fistname | Listname | Nickname |" <<std::endl;
	std::cout<< "==========================================" <<std::endl;
	if (idx >= 1 && idx <= 8)
		printDetailPhoneBook(idx - 1);
	else
		printAllPhoneBook();
}

void PhoneBook::title(void) const
{
	std::cout << std::endl;
	std::cout << "██████╗ ██╗  ██╗ ██████╗ ███╗   ██╗███████╗██████╗  ██████╗  ██████╗ ██╗  ██╗" << std::endl;
	std::cout << "██╔══██╗██║  ██║██╔═══██╗████╗  ██║██╔════╝██╔══██╗██╔═══██╗██╔═══██╗██║ ██╔╝" << std::endl;
	std::cout << "██████╔╝███████║██║   ██║██╔██╗ ██║█████╗  ██████╔╝██║   ██║██║   ██║█████╔╝ " << std::endl;
	std::cout << "██╔═══╝ ██╔══██║██║   ██║██║╚██╗██║██╔══╝  ██╔══██╗██║   ██║██║   ██║██╔═██╗ " << std::endl;
	std::cout << "██║     ██║  ██║╚██████╔╝██║ ╚████║███████╗██████╔╝╚██████╔╝╚██████╔╝██║  ██╗" << std::endl;
	std::cout << "╚═╝     ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝╚═════╝  ╚═════╝  ╚═════╝ ╚═╝  ╚═╝" << std::endl;
	std::cout << std::endl;
	std::cout << "Welcome to your phonebook !\nThe available entries are : " << std::endl;
	std::cout << " - ADD \n - SEARCH \n - EXIT \n" << std::endl;
}

void PhoneBook::end(void) const
{
	std::cout << "Good bye!" << std::endl;
}

int main()
{
	PhoneBook phoneBook;
	std::string command;

	phoneBook.title();
	while (true)
	{
		std::getline(std::cin, command);
		if (std::cin.eof())
			break ;
		else if (command.compare("ADD") == 0)
			phoneBook.addPhoneBook();
		else if (command.compare("SEARCH") == 0)
			phoneBook.printPhoneBook();
		else if (command.compare("EXIT") == 0)
			break;
		else
		{
			std::cout << "\"" << command << "\" is not a command. try again this" << std::endl;
			std::cout << " - ADD \n - SEARCH \n - EXIT \n" << std::endl;
		}
	}
	phoneBook.end();
}
