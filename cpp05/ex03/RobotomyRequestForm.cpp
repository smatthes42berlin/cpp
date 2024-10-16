/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:04:49 by smatthes          #+#    #+#             */
/*   Updated: 2024/10/16 11:14:39 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "external.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm",
	72, 45, false, "default")
{
	std::cout << "<default constructor> RobotomyRequestForm" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm",
	72, 45, false, target)
{
	std::cout << "<is_signed-target constructor> RobotomyRequestForm" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other.get_name(),
	other.get_grade_to_sign(), other.get_grade_to_execute(),
	other.get_is_signed(), other.get_target())
{
	std::cout << "<copy constructor> RobotomyRequestForm" << std::endl;
	return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "<copy assignment operator> RobotomyRequestForm" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "<destructor> RobotomyRequestForm" << std::endl;
	return ;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->check_can_be_executed(executor))
		this->execute_for_real();
}

void RobotomyRequestForm::execute_for_real(void) const
{
	int random_value;

	std::srand(static_cast<unsigned>(time(0)));
	random_value = std::rand() % 2;

	std::string noise_1 = "Brrrrrrr!";
	std::string noise_2 = "Drill!";
	std::string noise_3 = "Whirr!";

	std::cout << noise_1 << std::endl;
	std::cout << noise_2 << std::endl;
	std::cout << noise_3 << std::endl;
	std::cout << noise_3 << std::endl;
	std::cout << noise_2 << std::endl;
	std::cout << noise_1 << std::endl;

	if (random_value == 0)
	{
		std::cout << this->get_target();
		std::cout << " has been robotomized!";
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Robotomy failed";
		std::cout << std::endl;
	}
}
