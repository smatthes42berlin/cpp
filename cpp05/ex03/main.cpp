/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:30:21 by smatthes          #+#    #+#             */
/*   Updated: 2024/10/16 10:54:01 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "external.hpp"

void	test_form(AForm &Form, int sign_limit, int execute_limit);
void	test_bur_grade_too_low_to_sign(AForm &form, int sign_limit);
void	test_bur_grade_too_low_to_execute(AForm &form, int execute_limit);
void	test_form_not_signed(AForm &form);
void	test_sucessful(AForm &form);

int	main(void)
{
	//ShrubberyCreationForm sign 145 exec 137
	//RobotomyRequestForm sign 72 exec 45
	//PresidentialPardonForm sign 25 exec 5
	ShrubberyCreationForm form_shrub("you");
	RobotomyRequestForm form_robot("you");
	PresidentialPardonForm form_pardon("you");
	std::cout << std::endl;
	std::cout << "********Testing shrubbery********";
	std::cout << std::endl;
	test_form(form_shrub, 145, 137);
	std::cout << std::endl << std::endl;
	std::cout << std::endl;
	std::cout << "********Testing robotomy********";
	std::cout << std::endl;
	test_form(form_robot, 145, 137);
	std::cout << std::endl << std::endl;
	std::cout << std::endl;
	std::cout << "********Testing pardon********";
	std::cout << std::endl;
	test_form(form_pardon, 145, 137);
	std::cout << std::endl << std::endl;
	return (0);
}

void	test_bur_grade_too_low_to_sign(AForm &form, int sign_limit)
{
	Bureaucrat bur_grade_too_low_sign("bur_grade_too_low_sign", sign_limit + 1);
	try
	{
		bur_grade_too_low_sign.signForm(form);
	}
	catch (std::exception &err)
	{
		std::cerr << "**bur_grade_too_low_sign**" << std::endl;
		std::cerr << err.what() << std::endl;
	}
}

void	test_bur_grade_too_low_to_execute(AForm &form, int execute_limit)
{
	Bureaucrat bur_grade_too_low_execute("bur_grade_too_low_execute",
		execute_limit + 1);
	try
	{
		bur_grade_too_low_execute.signForm(form);
		bur_grade_too_low_execute.executeForm(form);
	}
	catch (std::exception &err)
	{
		std::cerr << "**bur_grade_too_low_execute**" << std::endl;
		std::cerr << err.what() << std::endl;
	}
}

void	test_form_not_signed(AForm &form)
{
	Bureaucrat bur_powerful("bur_powerful", 1);
	try
	{
		bur_powerful.executeForm(form);
	}
	catch (std::exception &err)
	{
		std::cerr << "**bur_powerful form not signed**" << std::endl;
		std::cerr << err.what() << std::endl;
	}
}

void	test_sucessful(AForm &form)
{
	Bureaucrat bur_powerful("bur_powerful", 1);
	try
	{
		bur_powerful.signForm(form);
		bur_powerful.executeForm(form);
	}
	catch (std::exception &err)
	{
		std::cerr << "**bur_grade_too_low_sign**" << std::endl;
		std::cerr << err.what() << std::endl;
	}
}

void	test_form(AForm &form, int sign_limit, int execute_limit)
{
	std::cout << std::endl << std::endl;
	test_bur_grade_too_low_to_sign(form, sign_limit);
	std::cout << std::endl << std::endl;
	test_form_not_signed(form);
	std::cout << std::endl << std::endl;
	test_bur_grade_too_low_to_execute(form, execute_limit);
	std::cout << std::endl << std::endl;
	test_sucessful(form);
}
