/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:30:21 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/21 20:58:11 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "external.hpp"

int	main(void)
{
	FragTrap FT1("FT1");
	
	std::cout << FT1;

	std::cout << std::endl;
	FT1.attack("Frag Enemy");
	std::cout << std::endl;
	FT1.takeDamage(99);
	std::cout << std::endl;
	FT1.beRepaired(1);
	std::cout << std::endl;
	FT1.highFivesGuys();
	std::cout << std::endl;
	FT1.takeDamage(99);
	std::cout << std::endl;
	FT1.takeDamage(99);
	std::cout << std::endl;
	FT1.highFivesGuys();
	


	std::cout << FT1;

	return (0);
}