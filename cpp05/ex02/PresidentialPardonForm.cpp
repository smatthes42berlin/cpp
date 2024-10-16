/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:18:58 by smatthes          #+#    #+#             */
/*   Updated: 2024/10/16 10:21:17 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "external.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm",
	25, 5, false, "default")
{
	std::cout << "<default constructor> PresidentialPardonForm" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm",
	25, 5, false, target)
{
	std::cout << "<is_signed-target constructor> PresidentialPardonForm" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other.get_name(),
	other.get_grade_to_sign(), other.get_grade_to_execute(),
	other.get_is_signed(), other.get_target())
{
	std::cout << "<copy constructor> PresidentialPardonForm" << std::endl;
	return ;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << "<copy assignment operator> PresidentialPardonForm" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "<destructor> PresidentialPardonForm" << std::endl;
	return ;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->check_can_be_executed(executor))
		this->execute_for_real();
}

void PresidentialPardonForm::execute_for_real(void) const
{
	std::cout << this->get_target();
	std::cout << " has been pardoned by Zaphod Beeblebrox!";
	std::cout << std::endl;
}
