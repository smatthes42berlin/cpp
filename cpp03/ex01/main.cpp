/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:30:21 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/23 15:42:13 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "external.hpp"

int	main(void)
{
	ScavTrap ST1("ST1");
	std::cout << std::endl;
	ScavTrap ST3(ST1);
	std::cout << std::endl;
	ScavTrap ST2("ST2");
	std::cout << std::endl;
	ScavTrap ST4;
	std::cout << std::endl;

	ST4 = ST2;

	std::cout << ST2 << std::endl;

	for (int i = 0; i < 51; i++)
	{
		ST2.beRepaired(1);
	}

	std::cout << ST2 << std::endl;
	ST1.attack("ScavEnemy");
	std::cout << std::endl;
	ST2.takeDamage(148);
	std::cout << ST2 << std::endl;
	ST2.guardGate();
	std::cout << ST2 << std::endl;
	ST2.takeDamage(5);
	std::cout << ST2 << std::endl;
	ST2.takeDamage(5);
	std::cout << ST2 << std::endl;
	ST2.beRepaired(1);
	std::cout << std::endl;
	ST2.guardGate();

	return (0);
}