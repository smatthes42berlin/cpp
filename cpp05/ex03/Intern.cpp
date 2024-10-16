/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:20:11 by smatthes          #+#    #+#             */
/*   Updated: 2024/10/16 11:30:33 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "external.hpp"

Intern::Intern(void)
{
	std::cout << "<default constructor> Intern" << std::endl;
	return ;
}

Intern::Intern(const Intern &other)
{
	std::cout << "<copy constructor> Intern" << std::endl;
	return ;
}

Intern &Intern::operator=(const Intern &other)
{
	std::cout << "<copy assignment operator> Intern" << std::endl;
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << "<destructor> Intern" << std::endl;
	return ;
}

AForm *Intern::makeForm(std::string form_name, std::string form_target) const
{
	const std::string formNames[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon",
		NULL // Sentinel to mark end of array
	};

	

	AForm *constructors[] = {&ShrubberyCreationForm::ShrubberyCreationForm,
		&RobotomyRequestForm::RobotomyRequestForm,
		&PresidentialPardonForm::PresidentialPardonForm, NULL};
}
