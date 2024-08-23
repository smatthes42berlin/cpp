/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:30:21 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/23 16:15:15 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "external.hpp"

int	main(void)
{
	FragTrap FT1("FT1");
	std::cout << std::endl;
	FragTrap FT3(FT1);
	std::cout << std::endl;
	FragTrap FT2("FT2");
	std::cout << std::endl;
	FragTrap FT4;
	std::cout << std::endl;

	FT4 = FT2;

	std::cout << FT2 << std::endl;

	for (int i = 0; i < 101; i++)
	{
		FT2.beRepaired(1);
	}

	std::cout << FT2 << std::endl;
	FT1.attack("ScavEnemy");
	std::cout << std::endl;
	FT2.takeDamage(198);
	std::cout << FT2 << std::endl;
	FT2.highFivesGuys();
	std::cout << FT2 << std::endl;
	FT2.takeDamage(5);
	std::cout << FT2 << std::endl;
	FT2.takeDamage(5);
	std::cout << FT2 << std::endl;
	FT2.beRepaired(1);
	std::cout << std::endl;
	FT2.highFivesGuys();

	return (0);
}