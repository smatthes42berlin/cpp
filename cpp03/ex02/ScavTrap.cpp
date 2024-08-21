/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:25:35 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/21 20:57:18 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "external.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap Default constructor called!" << std::endl;
	this->_initAttrDefaultScav();
	this->setName("newScavTrap");
	return ;
}

ScavTrap::ScavTrap(std::string trapName)
	: ClapTrap(trapName)
{
	std::cout << trapName << ": ScavTrap Constructor called!" << std::endl;
	this->_initAttrDefaultScav();
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &other)
	: ClapTrap()
{
	*this = other;
	std::cout << "A clone of ScavTrap " << this->getName() << " is constructed." << std::endl;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << this->getName() << ":ScavTrap Destructor called!" << std::endl;
	return ;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
}

void ScavTrap::_initAttrDefaultScav(void)
{
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
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
