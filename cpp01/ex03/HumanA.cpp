/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:16:45 by smatthes          #+#    #+#             */
/*   Updated: 2024/07/21 14:26:00 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "external.hpp"

HumanA::HumanA(std::string giveName, Weapon &giveWeapon)
	: _name(giveName), _weapon(giveWeapon)
{
	return ;
}

HumanA::~HumanA(void)
{
	return ;
}

void HumanA::attack(void) const
{
	std::cout << this->_name;
	std::cout << " attacks with their ";
	std::cout << this->_weapon.getType();
	std::cout << std::endl;
}
