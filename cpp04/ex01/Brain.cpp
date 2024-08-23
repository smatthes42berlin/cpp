/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:25:35 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/23 18:53:39 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "external.hpp"

Brain::Brain(void)
{
	std::cout << "<default constructor> Brain" << std::endl;
	this->fillWithOneIdea("default");
	return ;
}

Brain::Brain(const Brain &other)
{
	std::cout << "<default constructor> Brain" << std::endl;
	*this = other;
	return ;
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "<copy assignment operator> Brain" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
		{
			this->setIdea(i, other.getIdea(i));
		}
	}
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "<destructor> Brain" << std::endl;
	return ;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return (this->_ideas[index]);
	return ("");
}
void Brain::setIdea(int index, std::string idea)
{
	if (index >= 0 && index < 100)
		this->_ideas[index] = idea;
}

void Brain::fillWithOneIdea(std::string idea)
{
	for (int i = 0; i < 100; i++)
	{
		this->setIdea(i, idea);
	}
}

std::ostream &operator<<(std::ostream &os, Brain const &brain)
{
	os << std::endl;
	os << "All brain Ideas";
	os << std::endl;
	for (int i = 0; i < 100; i++)
	{
		os << i << "=";
		os << brain.getIdea(i);
		os << "\t";
	}
	os << std::endl;
	return (os);
}