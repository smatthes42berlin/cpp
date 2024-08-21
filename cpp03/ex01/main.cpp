/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:30:21 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/21 20:57:05 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "external.hpp"

int	main(void)
{
	ClapTrap CT1("CT1");
	ScavTrap CT2("CT2");
	std::cout << CT2;
	std::cout << CT1;

	CT1.attack("Clap Enemy");
	std::cout << std::endl;
	CT1.takeDamage(5);
	std::cout << std::endl;
	CT1.beRepaired(2);
	std::cout << std::endl;
	CT2.attack("Scav Enemy");
	std::cout << std::endl;
	CT2.takeDamage(5);
	std::cout << std::endl;
	CT2.beRepaired(2);
	std::cout << std::endl;
	CT2.guardGate();
	std::cout << std::endl;
	CT2.takeDamage(200);
	std::cout << std::endl;
	CT2.guardGate();
	
	std::cout << CT2;
	std::cout << CT1;
	return (0);
}