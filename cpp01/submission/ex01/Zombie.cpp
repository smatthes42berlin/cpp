/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes  <smatthes@student.42berlin>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:16:45 by smatthes          #+#    #+#             */
/*   Updated: 2024/07/21 10:16:45 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "external.hpp"

Zombie::Zombie(void)
{
	return ;
}

Zombie::Zombie(std::string name)
{
	this->setName(name);
	return ;
}

Zombie::~Zombie(void)
{
	return ;
}

void Zombie::announce(void) const
{
	std::cout << this->getName() << ": BraiiiiiiinnnzzzZ...";
	std::cout << std::endl;
}

void Zombie::setName(std::string name)
{
	this->_name = name;
	return ;
}

std::string Zombie::getName(void) const
{
	return (this->_name);
}
