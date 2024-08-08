/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:30:21 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/04 14:04:59 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "external.hpp"

int	main(void)
{
	ClapTrap CT1("CT1");
	ClapTrap CT2("CT2");
	ClapTrap CT3(CT1);
	ClapTrap CT4;
	std::string name;

	CT4 = CT2;

	std::cout << CT1 << std::endl;
	CT1.attack("CT2");
	std::cout << CT1 << std::endl;


	return (0);
}