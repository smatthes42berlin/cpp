/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:25:35 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/23 17:42:26 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "external.hpp"

Cat::Cat(void): Animal("Cat")
{
	std::cout << "<default constructor> Cat" << std::endl;
	return ;
}

Cat::Cat(const Cat &other) : Animal("Cat")
{
	*this = other;
	std::cout << "<copy constructor> Cat" << std::endl;
	return ;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "<copy assignment operator> Cat" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "<destructor> Cat" << std::endl;
	return ;
}

void Cat::makeSound(void) const
{
	std::cout << ">>Meow<<" << std::endl;
	return ;
}
