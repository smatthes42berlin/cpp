/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:22:39 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/23 15:22:29 by smatthes         ###   ########.fr       */
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

	void printDetail(std::ostream &os, std::string label,
		std::string (ClapTrap::*getter)() const) const;
	void printDetail(std::ostream &os, std::string label,
		unsigned int (ClapTrap::*getter)() const) const;

	std::string getName(void) const;
	unsigned int getHitPoints(void) const;
	unsigned int getEnergyPoints(void) const;
	unsigned int getAttackDamage(void) const;

  private:
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;
	static const int _printWidth = 20;

	void setName(std::string newName);
	void setHitPoints(unsigned int newHitPoints);
	void setEnergyPoints(unsigned int newEnergyPoints);
	void setAttackDamage(unsigned int newAttackDamage);

	bool reduceEnergyPoints(unsigned int amount);
	bool reduceHitPoints(unsigned int amount);
	bool isAlive(void) const;
};

std::ostream &operator<<(std::ostream &os, ClapTrap const &clapTrap);
