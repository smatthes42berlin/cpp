/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:30:21 by smatthes          #+#    #+#             */
/*   Updated: 2024/09/26 09:29:36 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "external.hpp"

void	test_default(void);
void	test_exceptions(void);
void	test_increment_too_high(void);
void	test_decrement_too_low(void);
void	test_constructor_too_high(void);
void	test_constructor_too_low(void);

int	main(void)
{
	test_default();
	test_exceptions();
	return (0);
}

void	test_default(void)
{
	Bureaucrat	B_default_default;

	Bureaucrat B_Olaf_Scholz_1("Olaf Scholz", 1);
	Bureaucrat B_Olaf_Scholz_150("Olaf Scholz", 150);
	Bureaucrat B_Olaf_Scholz_default("Olaf Scholz");
	Bureaucrat B_Olaf_Scholz_150_copy(B_Olaf_Scholz_150);
	Bureaucrat B_Robert_Habeck_75_copy_assignment("Robert Habeck", 75);
	std::cout << std::endl;
	std::cout << "1: " << B_Olaf_Scholz_1;
	std::cout << std::endl;
	std::cout << "2: " << B_Olaf_Scholz_150;
	std::cout << std::endl;
	std::cout << "3: " << B_Olaf_Scholz_default;
	std::cout << std::endl;
	std::cout << "4: " << B_default_default;
	std::cout << std::endl;
	std::cout << "5: " << B_Olaf_Scholz_150_copy;
	std::cout << std::endl;
	std::cout << "6: " << B_Robert_Habeck_75_copy_assignment;
	std::cout << std::endl;
	B_Robert_Habeck_75_copy_assignment = B_Olaf_Scholz_150;
	std::cout << "7: " << B_Robert_Habeck_75_copy_assignment;
	std::cout << std::endl;
	std::cout << "8: " << B_Olaf_Scholz_1.get_name();
	std::cout << std::endl;
	std::cout << "9: " << B_Olaf_Scholz_1.get_grade();
	std::cout << std::endl;
	B_Olaf_Scholz_1.decrement_grade();
	std::cout << "10: " << B_Olaf_Scholz_1.get_grade();
	std::cout << std::endl;
	B_Olaf_Scholz_1.increment_grade();
	std::cout << "11: " << B_Olaf_Scholz_1.get_grade();
	std::cout << std::endl;
}
void	test_exceptions(void)
{
	test_constructor_too_high();
	test_constructor_too_low();
	test_increment_too_high();
	test_decrement_too_low();
}

void	test_constructor_too_high(void)
{
	try
	{
		Bureaucrat Olaf_Scholz("Olaf Scholz", 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << std::endl;
	}
}

void	test_constructor_too_low(void)
{
	try
	{
		Bureaucrat Olaf_Scholz("Olaf Scholz", 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << std::endl;
	}
}

void	test_increment_too_high(void)
{
	Bureaucrat Olaf_Scholz("Olaf Scholz", 1);
	try
	{
		Olaf_Scholz.increment_grade();
		std::cout << Olaf_Scholz;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << Olaf_Scholz;
		std::cerr << std::endl;
	}
}

void	test_decrement_too_low(void)
{
	Bureaucrat Olaf_Scholz("Olaf Scholz", 150);
	try
	{
		Olaf_Scholz.decrement_grade();
		std::cout << Olaf_Scholz;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << Olaf_Scholz;
		std::cerr << std::endl;
	}
}
