/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:16:45 by smatthes          #+#    #+#             */
/*   Updated: 2024/07/25 10:12:10 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include "external.hpp"

int	main(void)
{
	Harl	harler;

	std::cout << "From: main call: DEBUG";
	std::cout << std::endl;
	harler.complain("DEBUG");
	std::cout << std::endl;
	std::cout << "From: main call: INFO";
	std::cout << std::endl;
	harler.complain("INFO");
	std::cout << std::endl;
	std::cout << "From: main call: WARNING";
	std::cout << std::endl;
	harler.complain("WARNING");
	std::cout << std::endl;
	std::cout << "From: main call: ERROR";
	std::cout << std::endl;
	harler.complain("ERROR");
	std::cout << std::endl;
	std::cout << "From: main call: unknown";
	std::cout << std::endl;
	harler.complain("unknown");
	std::cout << std::endl;
	return (0);
}
