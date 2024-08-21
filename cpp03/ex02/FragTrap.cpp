/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:25:35 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/21 20:58:31 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "external.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "FragTrap Default constructor called!" << std::endl;
	this->_initAttrDefaultFrag();
	this->setName("newFragTrap");
	return ;
}

FragTrap::FragTrap(std::string trapName)
	: ClapTrap(trapName)
{
	std::cout << trapName << ": FragTrap Constructor called!" << std::endl;
	this->_initAttrDefaultFrag();
	return ;
}

FragTrap::FragTrap(const FragTrap &other)
	: ClapTrap()
{
	*this = other;
	std::cout << "A clone of FragTrap " << this->getName() << " is constructed." << std::endl;
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << this->getName() << ":FragTrap Destructor called!" << std::endl;
	return ;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
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

void FragTrap::attack(const std::string &target)
{
	if (this->isAlive() && this->reduceEnergyPoints(1))
	{
		std::cout << "FragTrap ";
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
		std::cout << "FragTrap: No Energy or Hit Points, ";
		std::cout << this->getName();
		std::cout << " can't attack!";
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
