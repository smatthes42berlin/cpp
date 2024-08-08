/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:22:39 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/04 13:59:03 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "external.hpp"

#pragma once

class ClapTrap
{
  public:
	ClapTrap(void);
	ClapTrap(std::string trapName);
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);
	~ClapTrap(void);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void setName(std::string newName);
	std::string getName(void) const;

	void setHitPoints(unsigned int newHitPoints);
	unsigned int getHitPoints(void) const;
	void setEnergyPoints(unsigned int newEnergyPoints);
	unsigned int getEnergyPoints(void) const;
	void setAttackDamage(unsigned int newAttackDamage);
	unsigned int getAttackDamage(void) const;

	void printDetail(std::ostream &os, std::string label,
			std::string (ClapTrap::*getter)() const) const;
	void printDetail(std::ostream &os, std::string label,
			unsigned int (ClapTrap::*getter)() const) const;

  private:
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;
	static const int _printWidth = 20;

	void _initAttrDefault(void);
	bool _reduceEnergyPoints(unsigned int amount);
	bool _isAlive(void);
};

std::ostream &operator<<(std::ostream &os, ClapTrap const &clapTrap);