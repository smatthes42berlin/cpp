#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "external.hpp"

int	main(void)
{
	PhoneBook	phony;


	phony.fillPhoneBook();
	std::string userCmd;
	while (1)
	{
		std::cout << "Please enter 'ADD',";
		std::cout << "'SEARCH' or 'EXIT' depending on what you wanna do";
		std::cout << std::endl;
		std::getline(std::cin, userCmd);
		if (std::cin.eof())
			return (0);
		if (userCmd == "EXIT")
			break ;
		if (userCmd != "SEARCH" && userCmd != "ADD")
		{
			std::cout << "Unknown command!" << std::endl;
			continue ;
		}
		if (userCmd == "SEARCH")
			phony.search();
		if (userCmd == "ADD")
		{
			if (!phony.createNewContact())
				break ;
		}
	}
	return (0);
}
