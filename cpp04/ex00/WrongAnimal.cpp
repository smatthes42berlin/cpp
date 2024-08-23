/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:25:35 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/23 17:41:35 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "external.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
	std::cout << "<default constructor> WrongAnimal" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "<type constructor> WrongAnimal" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	*this = other;
	std::cout << "<copy constructor> WrongAnimal" << std::endl;
	return ;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "<copy assignment operator> WrongAnimal" << std::endl;
	if (this == &other)
	{
		return (*this);
	}
	this->_type = other._type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "<destructor> WrongAnimal" << std::endl;
	return ;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << ">>Base WrongAnimal Sound<<" << std::endl;
	return ;
}

std::string WrongAnimal::get_type(void) const
{
	return (this->_type);
}

void WrongAnimal::set_type(std::string new_type)
{
	this->_type = new_type;
}
