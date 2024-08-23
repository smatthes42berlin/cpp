/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:25:35 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/23 16:09:24 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "external.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "<Default constructor> FragTrap " << this->getName() << std::endl;
	this->_initAttrDefaultFrag();
	return ;
}

FragTrap::FragTrap(std::string trapName) 
{
	this->setName(trapName);
	std::cout << "<Name constructor> FragTrap " << trapName << std::endl;
	this->_initAttrDefaultFrag();
	return ;
}

FragTrap::FragTrap(const FragTrap &other) 
{
	this->setName("NAMELESS");
	std::cout << "<Copy constructor> FragTrap " << this->getName() << std::endl;
	*this = other;
	return ;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "<Copy assignment operator> ";
	std::cout << "FragTrap " << this->getName() << " is now a clone of";
	std::cout << " FragTrap " << other.getName() << std::endl;
	if (this == &other)
	{
		return (*this);
	}
	this->setName(other.getName());
	this->setHitPoints(other.getHitPoints());
	this->setEnergyPoints(other.getEnergyPoints());
	this->setAttackDamage(other.getAttackDamage());
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "<Destructor> FragTrap " << this->getName() << std::endl;
	return ;
}

void FragTrap::_initAttrDefaultFrag(void)
{
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

void FragTrap::highFivesGuys(void) const
{
	if (this->isAlive())
	{
		std::cout << this->getName() << ": FragTrap sucessfully high fived you!";
		std::cout << std::endl;
	}
	else
	{
		std::cout << this->getName() << ": FragTrap can't high five you, it's dead!";
		std::cout << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, FragTrap const &fragTrap)
{
	os << std::endl;
	os << "FragTrap instance Details";
	os << std::endl;
	fragTrap.printDetail(os, "Name", &FragTrap::getName);
	fragTrap.printDetail(os, "Hitpoints", &FragTrap::getHitPoints);
	fragTrap.printDetail(os, "Energy Points", &FragTrap::getEnergyPoints);
	fragTrap.printDetail(os, "Attack Damage", &FragTrap::getAttackDamage);
	os << std::endl;
	return (os);
}
