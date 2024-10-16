/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:25:35 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/30 16:42:43 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "external.hpp"

Dog::Dog(void) : A_Animal("Dog"), _brain(new Brain)
{
	std::cout << "<default constructor> Dog" << std::endl;
	return ;
}

Dog::Dog(const Dog &other) : A_Animal("Dog"), _brain(NULL)
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
		A_Animal::operator=(other);
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return (*this);
}

Brain *Dog::getBrain() const
{
	return (this->_brain);
}

Dog::~Dog(void)
{
	std::cout << "<destructor> Dog" << std::endl;
	delete this->_brain;
	return ;
}

void Dog::makeSound(void) const
{
	std::cout << ">>Woof<<" << std::endl;
	return ;
}
