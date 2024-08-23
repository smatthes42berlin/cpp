/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:25:35 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/23 17:42:26 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "external.hpp"

WrongCat::WrongCat(void): WrongAnimal("WrongCat")
{
	std::cout << "<default constructor> WrongCat" << std::endl;
	return ;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal("WrongCat")
{
	*this = other;
	std::cout << "<copy constructor> WrongCat" << std::endl;
	return ;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "<copy assignment operator> WrongCat" << std::endl;
	if (this != &other)
	{
		WrongAnimal::operator=(other);
	}
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "<destructor> WrongCat" << std::endl;
	return ;
}

void WrongCat::makeSound(void) const
{
	std::cout << ">>Meow<<" << std::endl;
	return ;
}
