/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:30:21 by smatthes          #+#    #+#             */
/*   Updated: 2024/09/05 09:57:09 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "external.hpp"

void	test_default(void)
{
	Bureaucrat B_default_default;

	Bureaucrat B_Olaf_Scholz_1("Olaf Scholz", 1);
	Bureaucrat B_Olaf_Scholz_150("Olaf Scholz", 150);
	Bureaucrat B_Olaf_Scholz_default("Olaf Scholz");
	Bureaucrat B_Olaf_Scholz_150_copy(B_Olaf_Scholz_150);
	Bureaucrat B_Robert_Habeck_75_copy_assignment("Robert Habeck", 75);
	
	std::cout << std::endl;
	std::cout << B_Olaf_Scholz_1;
	std::cout << std::endl;
	std::cout << B_Olaf_Scholz_150;
	std::cout << std::endl;
	std::cout << B_Olaf_Scholz_default;
	std::cout << std::endl;
	std::cout << B_default_default;
	std::cout << std::endl;
	std::cout << B_Olaf_Scholz_150_copy;
	std::cout << std::endl;
	std::cout << B_Robert_Habeck_75_copy_assignment;
	std::cout << std::endl;
	B_Robert_Habeck_75_copy_assignment = B_Olaf_Scholz_150;
	std::cout << B_Robert_Habeck_75_copy_assignment;
	std::cout << std::endl;
	std::cout << B_Olaf_Scholz_1.get_name();
	std::cout << std::endl;
	std::cout << B_Olaf_Scholz_1.get_grade();
	std::cout << std::endl;
}
void	test_exceptions(void);

int	main(void)
{
	test_default();
	// Bureaucrat Olaf_Scholz("Olaf Scholz", 1);
	// std::cout << Olaf_Scholz;
	// // std::cout << Olaf_Scholz;
	// // Olaf_Scholz.increment_grade();
	// // std::cout << Olaf_Scholz;
	// // Olaf_Scholz.decrement_grade();
	// // std::cout << Olaf_Scholz;
	// try
	// {
	// 	Olaf_Scholz.increment_grade();
	// 	std::cout << Olaf_Scholz;
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// 	std::cout << Olaf_Scholz;
	// }
	return (0);
}
