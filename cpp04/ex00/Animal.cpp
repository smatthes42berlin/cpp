/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:25:35 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/23 17:41:35 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "external.hpp"

Animal::Animal(void) : _type("Animal")
{
	std::cout << "<default constructor> Animal" << std::endl;
	return ;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "<type constructor> Animal" << std::endl;
	return ;
}

Animal::Animal(const Animal &other)
{
	*this = other;
	std::cout << "<copy constructor> Animal" << std::endl;
	return ;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "<copy assignment operator> Animal" << std::endl;
	if (this == &other)
	{
		return (*this);
	}
	this->_type = other._type;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "<destructor> Animal" << std::endl;
	return ;
}

void Animal::makeSound(void) const
{
	std::cout << ">>Base Animal Sound<<" << std::endl;
	return ;
}

std::string Animal::get_type(void) const
{
	return (this->_type);
}

void Animal::set_type(std::string new_type)
{
	this->_type = new_type;
}
