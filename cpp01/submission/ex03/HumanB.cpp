/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:16:45 by smatthes          #+#    #+#             */
/*   Updated: 2024/07/21 14:34:05 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "external.hpp"

HumanB::HumanB(std::string name)
	: _name(name), _weapon(NULL)
{
	return ;
}

HumanB::~HumanB(void)
{
	return ;
}

void HumanB::setWeapon(Weapon &giveWeapon)
{
	this->_weapon = &giveWeapon;
	return ;
}

void HumanB::attack(void) const
{
	if (this->_weapon)
	{
		std::cout << this->_name;
		std::cout << " attacks with their ";
		std::cout << this->_weapon->getType();
		std::cout << std::endl;
	}
	else
	{
		std::cout << this->_name << " has no weapon!" << std::endl;
	}
}
