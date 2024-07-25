/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes  <smatthes@student.42berlin>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:18:40 by smatthes          #+#    #+#             */
/*   Updated: 2024/07/18 14:25:16 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void Contact::setFirstName(std::string firstName)
{
	this->_firstName = firstName;
	return ;
}
void Contact::setLastName(std::string lastName)
{
	this->_lastName = lastName;
	return ;
}
void Contact::setNickName(std::string nickName)
{
	this->_nickName = nickName;
	return ;
}
void Contact::setDarkestSecret(std::string darkestSecret)
{
	this->_darkestSecret = darkestSecret;
	return ;
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
	this->_phoneNumber = phoneNumber;
	return ;
}

std::string Contact::getFirstName(void) const
{
	return (this->_firstName);
}

std::string Contact::getLastName(void) const
{
	return (this->_lastName);
}

std::string Contact::getNickName(void) const
{
	return (this->_nickName);
}

std::string Contact::getDarkestSecret(void) const
{
	return (this->_darkestSecret);
}

std::string Contact::getPhoneNumber(void) const
{
	return (this->_phoneNumber);
}
