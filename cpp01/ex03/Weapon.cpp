/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:16:45 by smatthes          #+#    #+#             */
/*   Updated: 2024/07/21 13:46:12 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "external.hpp"

Weapon::Weapon(void)
{
	return ;
}

Weapon::Weapon(std::string type)
{
	this->setType(type);
	return ;
}

Weapon::~Weapon(void)
{
	return ;
}

void Weapon::setType(std::string type)
{
	this->_type = type;
	return ;
}

std::string Weapon::getType(void) const
{
	return (this->_type);
}
