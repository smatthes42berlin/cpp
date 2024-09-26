/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:30:21 by smatthes          #+#    #+#             */
/*   Updated: 2024/09/26 11:11:19 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "external.hpp"

void	test_form_constructor_too_high(void);
void	test_form_constructor_too_low(void);
void	test_form_be_signed(void);
void	test_bureaucrat_sign_form(void);

int	main(void)
{
	test_form_constructor_too_high();
	test_form_constructor_too_low();
	test_form_be_signed();
	test_bureaucrat_sign_form();
	return (0);
}

void	test_form_constructor_too_high(void)
{
	try
	{
		Form test("Test", 0, 1);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << std::endl;
	}
}

void	test_form_constructor_too_low(void)
{
	try
	{
		Form test("Test", 1, 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << std::endl;
	}
}

void	test_form_be_signed(void)
{
	Form test_form("Test_Form", 12, 1);
	Bureaucrat test_bureaucrat_too_low("Test_Bureacrat", 15);
	Bureaucrat test_bureaucrat_eligable("Test_Bureacrat", 3);
	std::cout << test_form << std::endl;
	std::cout << test_bureaucrat_too_low << std::endl;
	try
	{
		test_form.beSigned(test_bureaucrat_too_low);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << std::endl;
	}
	std::cout << test_form << std::endl;
	std::cout << test_bureaucrat_eligable << std::endl;
	try
	{
		test_form.beSigned(test_bureaucrat_eligable);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << std::endl;
	}
	std::cout << test_form << std::endl;
}

void	test_bureaucrat_sign_form(void)
{
	Form test_form("Test_Form", 12, 1);
	Bureaucrat test_bureaucrat_too_low("Test_Bureacrat", 15);
	Bureaucrat test_bureaucrat_eligable("Test_Bureacrat", 3);
	test_bureaucrat_too_low.signForm(test_form);
	std::cout << test_form << std::endl;	
	test_bureaucrat_eligable.signForm(test_form);
	std::cout << test_form << std::endl;
}
