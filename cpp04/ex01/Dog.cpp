/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:25:35 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/23 17:42:48 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "external.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "<default constructor> Dog" << std::endl;
	return ;
}

Dog::Dog(const Dog &other) : Animal("Dog")
{
	*this = other;
	std::cout << "<copy constructor> Dog" << std::endl;
	return ;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "<copy assignment operator> Dog" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "<destructor> Dog" << std::endl;
	return ;
}

void Dog::makeSound(void) const
{
	std::cout << ">>Woof<<" << std::endl;
	return ;
}
