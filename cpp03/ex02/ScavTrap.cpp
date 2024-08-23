/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:25:35 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/23 15:38:59 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "external.hpp"

ScavTrap::ScavTrap(void) 
{
	std::cout << "<Default constructor> ScavTrap " << this->getName() << std::endl;
	this->_initAttrDefaultScav();
	return ;
}

ScavTrap::ScavTrap(std::string trapName) 
{
	this->setName(trapName);
	std::cout << "<Name constructor> ScavTrap " << trapName << std::endl;
	this->_initAttrDefaultScav();
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &other) 
{
	this->setName("NAMELESS");
	std::cout << "<Copy constructor> ScavTrap " << this->getName() << std::endl;
	*this = other;
	return ;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "<Copy assignment operator> ";
	std::cout << "ScavTrap " << this->getName() << " is now a clone of";
	std::cout << " ScavTrap " << other.getName() << std::endl;
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

ScavTrap::~ScavTrap(void)
{
	std::cout << "<Destructor> ScavTrap " << this->getName() << std::endl;
	return ;
}

void ScavTrap::guardGate(void) const
{
	if (this->isAlive())
	{
		std::cout << this->getName() << ": ScavTrap is now in Gate keeper mode!";
		std::cout << std::endl;
	}
	else
	{
		std::cout << this->getName() << ": ScavTrap can't enter Gate keeper mode,";
		std::cout << " it's dead!";
		std::cout << std::endl;
	}
}

void ScavTrap::attack(const std::string &target)
{
	if (this->isAlive() && this->reduceEnergyPoints(1))
	{
		std::cout << "ScavTrap ";
		std::cout << this->getName();
		std::cout << " attacks ";
		std::cout << target;
		std::cout << ",causing ";
		std::cout << this->getAttackDamage();
		std::cout << " points of damage!";
		std::cout << std::endl;
	}
	else
	{
		std::cout << "ScavTrap: No Energy or Hit Points, ";
		std::cout << this->getName();
		std::cout << " can't attack!";
		std::cout << std::endl;
	}
}

void ScavTrap::_initAttrDefaultScav(void)
{
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

std::ostream &operator<<(std::ostream &os, ScavTrap const &scavTrap)
{
	os << std::endl;
	os << "ScavTrap instance Details";
	os << std::endl;
	scavTrap.printDetail(os, "Name", &ScavTrap::getName);
	scavTrap.printDetail(os, "Hitpoints", &ScavTrap::getHitPoints);
	scavTrap.printDetail(os, "Energy Points", &ScavTrap::getEnergyPoints);
	scavTrap.printDetail(os, "Attack Damage", &ScavTrap::getAttackDamage);
	os << std::endl;
	return (os);
}
