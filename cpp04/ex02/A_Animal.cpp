/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:25:35 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/23 17:41:35 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A_Animal.hpp"
#include "external.hpp"

A_Animal::A_Animal(void) : _type("A_Animal")
{
	std::cout << "<default constructor> A_Animal" << std::endl;
	return ;
}

A_Animal::A_Animal(std::string type) : _type(type)
{
	std::cout << "<type constructor> A_Animal" << std::endl;
	return ;
}

A_Animal::A_Animal(const A_Animal &other)
{
	*this = other;
	std::cout << "<copy constructor> A_Animal" << std::endl;
	return ;
}

A_Animal &A_Animal::operator=(const A_Animal &other)
{
	std::cout << "<copy assignment operator> A_Animal" << std::endl;
	if (this == &other)
	{
		return (*this);
	}
	this->_type = other._type;
	return (*this);
}

A_Animal::~A_Animal(void)
{
	std::cout << "<destructor> A_Animal" << std::endl;
	return ;
}

void A_Animal::makeSound(void) const
{
	std::cout << ">>Base A_Animal Sound<<" << std::endl;
	return ;
}

std::string A_Animal::get_type(void) const
{
	return (this->_type);
}

void A_Animal::set_type(std::string new_type)
{
	this->_type = new_type;
}
