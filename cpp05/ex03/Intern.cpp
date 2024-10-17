/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:20:11 by smatthes          #+#    #+#             */
/*   Updated: 2024/10/16 14:26:17 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "<default constructor> Intern" << std::endl;
	return ;
}

Intern::Intern(const Intern &other)
{
	(void)other;
	std::cout << "<copy constructor> Intern" << std::endl;
	return ;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	std::cout << "<copy assignment operator> Intern" << std::endl;
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << "<destructor> Intern" << std::endl;
	return ;
}

const char *Intern::InvalidFormRequestException::what() const throw()
{
	return ("Intern: Requested form does not exist!");
}

AForm *Intern::makeShrubbery(std::string target) const
{
	std::cout << "Intern creates ShrubberyCreationForm";
	std::cout << std::endl;
	return (new ShrubberyCreationForm(target));
}
AForm *Intern::makePresidential(std::string target) const
{
	std::cout << "Intern creates PresidentialPardonForm";
	std::cout << std::endl;
	return (new PresidentialPardonForm(target));
}
AForm *Intern::makeRobotomy(std::string target) const
{
	std::cout << "Intern creates RobotomyRequestForm";
	std::cout << std::endl;
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makeForm(std::string form_name, std::string form_target) const
{
	const std::string form_names[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon",
	};

	AForm *(Intern::*constructors[])(std::string target) const = {&Intern::makeShrubbery,
		&Intern::makeRobotomy, &Intern::makePresidential};

	for (int i = 0; i < 3; i++)
	{
		if (form_name == form_names[i])
		{
			return (this->*(constructors[i]))(form_target);
		}
	}

	throw InvalidFormRequestException();
	return (NULL);
}
