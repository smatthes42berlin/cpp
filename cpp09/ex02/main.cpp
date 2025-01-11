/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:01:18 by smatthes          #+#    #+#             */
/*   Updated: 2025/01/11 17:17:07 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "external.hpp"

int	main(int argc, char *argv[])
{
	if (argc <= 1)
	{
		std::cout << "Please provide at least one postive integer as argument!";
		std::cout << std::endl;
		return (1);
	}
	PmergeMe test(argc, argv);
	try
	{
		test.sort();
	}
	catch(std::exception &err)
	{
		std::cerr << err.what() << std::endl;
	}
	return (0);
}
