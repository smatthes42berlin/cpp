/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:25:35 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/21 20:54:12 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "external.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "Claptrap Default constructor called!" << std::endl;
	this->_initAttrDefaultClap();
	this->setName("newClapTrap");
	return ;
}

ClapTrap::ClapTrap(std::string trapName)
{
	std::cout << trapName << ": Claptrap Constructor called!" << std::endl;
	this->_initAttrDefaultClap();
	this->setName(trapName);
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << "A clone of ClapTrap " << this->getName() << " is constructed." << std::endl;
	return ;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this == &other)
	{
		return (*this);
	}
	std::cout << "ClapTrap " << this->getName();
	this->setName(other.getName());
	this->setHitPoints(other.getHitPoints());
	this->setEnergyPoints(other.getEnergyPoints());
	this->setAttackDamage(other.getAttackDamage());
	std::cout << " is now a clone of ClapTrap " << this->getName() << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << this->getName() << ":Claptrap Destructor called!" << std::endl;
	return ;
}

void ClapTrap::_initAttrDefaultClap(void)
{
	this->setHitPoints(10);
	this->setEnergyPoints(10);
	this->setAttackDamage(0);
}

void ClapTrap::attack(const std::string &target)
{
	if (this->isAlive() && this->reduceEnergyPoints(1))
	{
		std::cout << "ClapTrap ";
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
		std::cout << "No Energy or Hit Points, ";
		std::cout << this->getName();
		std::cout << " can't attack!";
		std::cout << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "Claptrap ";
	std::cout << this->getName();
	if (!this->isAlive())
	{
		std::cout << " can't take anymore damage, ";
		std::cout << " it's already dead!";
		std::cout << std::endl;
		return ;
	}
	if (!this->reduceHitPoints(amount))
	{
		std::cout << " takes ";
		std::cout << amount;
		std::cout << " points of damage and dies!";
		std::cout << std::endl;
		return ;
	}
	std::cout << " takes ";
	std::cout << amount;
	std::cout << " points of damage and lives on to fight another day!";
	std::cout << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->isAlive() && this->reduceEnergyPoints(1))
	{
		this->setHitPoints(this->getHitPoints() + amount);
		std::cout << "ClapTrap ";
		std::cout << this->getName();
		std::cout << " repairs itself by ";
		std::cout << amount;
		std::cout << " points!";
		std::cout << std::endl;
	}
	else
	{
		std::cout << "No Energy or Hit Points, ";
		std::cout << this->getName();
		std::cout << " can't repair!";
		std::cout << std::endl;
	}
}

void ClapTrap::setName(std::string newName)
{
	this->_name = newName;
}

std::string ClapTrap::getName(void) const
{
	return (this->_name);
}

void ClapTrap::setHitPoints(unsigned int newHitPoints)
{
	this->_hitPoints = newHitPoints;
}

unsigned int ClapTrap::getHitPoints(void) const
{
	return (this->_hitPoints);
}

void ClapTrap::setEnergyPoints(unsigned int newEnergyPoints)
{
	this->_energyPoints = newEnergyPoints;
}
unsigned int ClapTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}

void ClapTrap::setAttackDamage(unsigned int newAttackDamage)
{
	this->_attackDamage = newAttackDamage;
}

unsigned int ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

std::ostream &operator<<(std::ostream &os, ClapTrap const &clapTrap)
{
	os << std::endl;
	os << "ClapTrap instance Details";
	os << std::endl;
	clapTrap.printDetail(os, "Name", &ClapTrap::getName);
	clapTrap.printDetail(os, "Hitpoints", &ClapTrap::getHitPoints);
	clapTrap.printDetail(os, "Energy Points", &ClapTrap::getEnergyPoints);
	clapTrap.printDetail(os, "Attack Damage", &ClapTrap::getAttackDamage);
	os << std::endl;
	return (os);
}

void ClapTrap::printDetail(std::ostream &os, std::string label,
		std::string (ClapTrap::*getter)() const) const
{
	std::string value = (this->*getter)();
	os << std::left << std::setw(ClapTrap::_printWidth) << label << ": ";
	os << value << std::endl;
}

void ClapTrap::printDetail(std::ostream &os, std::string label,
		unsigned int (ClapTrap::*getter)() const) const
{
	unsigned int value = (this->*getter)();
	os << std::left << std::setw(ClapTrap::_printWidth) << label << ": ";
	os << value << std::endl;
}

bool ClapTrap::reduceEnergyPoints(unsigned int amount)
{
	unsigned int	curEnergyPoints;

	curEnergyPoints = this->getEnergyPoints();
	if (curEnergyPoints < amount)
		return (false);
	this->setEnergyPoints(curEnergyPoints - amount);
	return (true);
}

bool ClapTrap::reduceHitPoints(unsigned int amount)
{
	unsigned int	curHitPoints;

	curHitPoints = this->getHitPoints();
	if (curHitPoints <= amount)
	{
		this->setHitPoints(0);
		return (false);
	}
	this->setHitPoints(curHitPoints - amount);
	return (true);
}

bool ClapTrap::isAlive(void) const
{
	return (this->getHitPoints() > 0);
}
