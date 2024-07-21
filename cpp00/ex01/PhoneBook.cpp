/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:18:25 by smatthes          #+#    #+#             */
/*   Updated: 2024/07/21 10:43:52 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

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
		return (false);
	newContact.setFirstName(userInput);
	userInput = this->_getUserInput("Last Name");
	if (userInput.length() == 0)
		return (false);
	newContact.setLastName(userInput);
	userInput = this->_getUserInput("Nick Name");
	if (userInput.length() == 0)
		return (false);
	newContact.setNickName(userInput);
	userInput = this->_getUserInput("Phone Number");
	if (userInput.length() == 0)
		return (false);
	newContact.setPhoneNumber(userInput);
	userInput = this->_getUserInput("Darkest Secret");
	if (userInput.length() == 0)
		return (false);
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
		if (std::cin.eof())
			return ("");
		if (!detail.empty())
			break ;
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

int PhoneBook::_getUserInt(void) const
{
	int index;

	std::cout << "Enter the index of the entry you wanna display:" << std::endl;
	std::cin >> index;
	if (std::cin.eof())
		return (-2);
	if (index < 1 || index > PhoneBook::_maxNbrContacts
		|| index > this->_nbrContacts || std::cin.fail())
	{
		std::cout << "Invalid integer. Please enter an integer corresponding to a phone book entries index!";
		std::cout << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return (-1);
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return (index);
}

void PhoneBook::search(void) const
{
	int index;
	if (this->_nbrContacts < 1)
	{
		std::cout << "There are currently no contacts in the phonebook,";
		std::cout << "please enter some!";
		std::cout << std::endl;
		return ;
	}
	this->_printAllContacts();
	while (true)
	{
		index = this->_getUserInt();
		if (index == -2)
			return ;
		if (index >= 0)
			break ;
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
	std::cout << "     index";
	std::cout << "|";
	std::cout << "First Name";
	std::cout << "|";
	std::cout << " Last Name";
	std::cout << "|";
	std::cout << " Nick Name" << std::endl;
	for (int i = 0; i < this->_nbrContacts; i++)
	{
		this->_formatColumn(i + 1);
		std::cout << this->_formatColumn(this->_contactsStored[i].getFirstName()) << "|";
		std::cout << this->_formatColumn(this->_contactsStored[i].getLastName()) << "|";
		std::cout << this->_formatColumn(this->_contactsStored[i].getNickName());
		std::cout << std::endl;
	}
}

void PhoneBook::_formatColumn(int index) const
{
	std::cout << "         ";
	std::cout << index;
	std::cout << "|";
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

void PhoneBook::fillPhoneBook(void)
{
	Contact	c;

	for (int i = 0; i < this->_maxNbrContacts; i++)
	{
		std::string val(5, '0' + i);
		std::cout << "adding" << std::endl;
		c.setFirstName(val);
		c.setLastName(val);
		c.setNickName(val);
		c.setPhoneNumber(val);
		c.setDarkestSecret(val);
		this->_add(c);
	}
}

int PhoneBook::_nbrContacts = 0;
int PhoneBook::_maxNbrContacts = 8;
int PhoneBook::_contactLastAdded = 0;