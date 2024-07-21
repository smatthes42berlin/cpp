/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:31:07 by smatthes          #+#    #+#             */
/*   Updated: 2024/07/21 10:44:48 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "memory address string variable = " << &string;
	std::cout << std::endl;
	std::cout << "memory address held by stringPTR = " << stringPTR;
	std::cout << std::endl;
	std::cout << "memory address held by stringREF = " << &stringREF;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "value string variable = " << string;
	std::cout << std::endl;
	std::cout << "value pointed to by stringPTR = " << *stringPTR;
	std::cout << std::endl;
	std::cout << "value pointed to by stringREF = " << stringREF;
	std::cout << std::endl;

	return (0);
}