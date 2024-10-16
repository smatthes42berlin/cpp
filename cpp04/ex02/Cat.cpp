/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:25:35 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/30 16:42:38 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "external.hpp"

Cat::Cat(void) : A_Animal("Cat"), _brain(new Brain)
{
	std::cout << "<default constructor> Cat" << std::endl;
	return ;
}

Cat::Cat(const Cat &other) : A_Animal("Cat"), _brain(NULL)
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
		A_Animal::operator=(other);
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return (*this);
}

Brain *Cat::getBrain() const
{
	return (this->_brain);
}

Cat::~Cat(void)
{
	std::cout << "<destructor> Cat" << std::endl;
	delete this->_brain;
	return ;
}

void Cat::makeSound(void) const
{
	std::cout << ">>Meow<<" << std::endl;
	return ;
}
