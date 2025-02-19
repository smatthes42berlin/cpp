/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:30:21 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/21 20:32:05 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "external.hpp"

int	main(void)
{
	ClapTrap CT1("CT1");
	ClapTrap CT3(CT1);
	ClapTrap CT2("CT2");
	ClapTrap CT4;

	CT4 = CT2;

	std::cout << CT2 << std::endl;
	CT2.beRepaired(1);
	CT2.beRepaired(1);
	CT2.beRepaired(1);
	CT2.beRepaired(1);
	CT2.beRepaired(1);
	CT2.beRepaired(1);
	CT2.beRepaired(1);
	CT2.beRepaired(1);
	CT2.beRepaired(1);
	CT2.beRepaired(1);
	CT2.beRepaired(1);


	std::cout << CT2 << std::endl;
	CT1.attack("CT2");
	CT2.takeDamage(19);
	std::cout << CT2 << std::endl;
	CT2.takeDamage(5);
	std::cout << CT2 << std::endl;
	CT2.takeDamage(5);
	std::cout << CT2 << std::endl;
	CT2.beRepaired(1);
	return (0);
}