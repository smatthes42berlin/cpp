/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:22:39 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/10 16:29:58 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "external.hpp"

#pragma once

class ScavTrap : public ClapTrap
{
  public:
	ScavTrap(void);
	ScavTrap(std::string trapName);
	ScavTrap(const ScavTrap &other);
	ScavTrap &operator=(const ScavTrap &other);
	~ScavTrap(void);

	void guardGate(void) const;
	void attack(const std::string &target);

  private:
	void _initAttrDefaultScav(void);
};

std::ostream &operator<<(std::ostream &os, ScavTrap const &ScavTrap);