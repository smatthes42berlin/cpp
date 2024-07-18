#include "Contact.hpp"
#include "PhoneBook.hpp"

// void	ignoreLine(void)
// {
// 	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
// }

PhoneBook::PhoneBook(void)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

bool PhoneBook::createNewContact(void)
{
	Contact	newContact;

	std::string userInput;
	std::cout << "Creating a new Contact" << std::endl;
	userInput = this->_getUserInput("First Name");
	if (userInput.length() == 0)
	{
		std::cin.clear();
		return (false);
	}
	newContact.setFirstName(userInput);
	userInput = this->_getUserInput("Last Name");
	if (userInput.length() == 0)
	{
		std::cin.clear();
		return (false);
	}
	newContact.setLastName(userInput);
	userInput = this->_getUserInput("Nick Name");
	if (userInput.length() == 0)
	{
		std::cin.clear();
		return (false);
	}
	newContact.setNickName(userInput);
	userInput = this->_getUserInput("Phone Number");
	if (userInput.length() == 0)
	{
		std::cin.clear();
		return (false);
	}
	newContact.setPhoneNumber(userInput);
	userInput = this->_getUserInput("Darkest Secret");
	if (userInput.length() == 0)
	{
		std::cin.clear();
		return (false);
	}
	newContact.setDarkestSecret(userInput);
	this->_add(newContact);
	std::cout << "hi!";
	return (true);
}

std::string PhoneBook::_getUserInput(const std::string prompt) const
{
	std::string detail;
	while (1)
	{
		std::cout << "Enter " << prompt << std::endl;
		std::getline(std::cin, detail);
		if (!detail.empty())
			break ;
		if (std::cin.eof())
		{
			return ("");
		}
		std::cout << "Input cannot be empty." << std::endl;
	}
	return (detail);
}

void PhoneBook::_add(Contact newContact)
{
	this->_contactsStored[_contactLastAdded] = newContact;
	this->_contactLastAdded = (this->_contactLastAdded + 1)
		% PhoneBook::_maxNbrContacts;
	if (this->_nbrContacts < PhoneBook::_maxNbrContacts)
	{
		this->_nbrContacts++;
	}
	return ;
}

void PhoneBook::search(void) const
{
	int index;
	int maxC = PhoneBook::_maxNbrContacts;
	if (this->_nbrContacts < 1)
	{
		std::cout << "There are currently no contacts in the phonebook,";
		std::cout << "please enter some!";
		std::cout << std::endl;
		return ;
	}
	this->_printAllContacts();
	std::cout << "Enter the index of the entry you wanna display:" << std::endl;
	// std::cin.clear();
	// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin >> index;
	if (index < 1 || index > maxC)
	{
		std::cout << "The Phonebook can store between 1 and ";
		std::cout << maxC << " contacts,";
		std::cout << " please enter a number between 1 and ";
		std::cout << maxC << " !" << std::endl;
		return ;
	}
	if (index > this->_nbrContacts)
	{
		std::cout << "There are currently " << this->_nbrContacts;
		std::cout << " contacts in the phonebook,";
		std::cout << " please provide an index between 1 and ";
		std::cout << this->_nbrContacts << std::endl;
		return ;
	}
	this->_printContact(index);
}

void PhoneBook::_printContact(int index) const
{
	Contact con = this->_contactsStored[index - 1];
	std::cout << "First Name: " << con.getFirstName() << std::endl;
	std::cout << "Last Name: " << con.getLastName() << std::endl;
	std::cout << "Nick Name: " << con.getNickName() << std::endl;
	std::cout << "Phone: " << con.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << con.getDarkestSecret() << std::endl;
}

void PhoneBook::_printAllContacts(void) const
{
	for (int i = 0; i < this->_nbrContacts; i++)
	{
		std::cout << i + 1 << "|";
		std::cout << this->_formatColumn(this->_contactsStored[i].getFirstName()) << "|";
		std::cout << this->_formatColumn(this->_contactsStored[i].getLastName()) << "|";
		std::cout << this->_formatColumn(this->_contactsStored[i].getNickName());
		std::cout << std::endl;
	}
}

std::string PhoneBook::_formatColumn(const std::string text) const
{
	std::string result = text;
	if (text.length() > 10)
	{
		result = text.substr(0, 10 - 1) + '.';
	}
	return (std::string(10 - result.length(), ' ') + result);
}

int PhoneBook::_nbrContacts = 0;
int PhoneBook::_maxNbrContacts = 8;
int PhoneBook::_contactLastAdded = 0;