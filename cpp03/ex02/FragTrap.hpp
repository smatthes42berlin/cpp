/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:22:39 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/21 20:46:00 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "external.hpp"

#pragma once

class FragTrap : public ClapTrap
{
  public:
	FragTrap(void);
	FragTrap(std::string trapName);
	FragTrap(const FragTrap &other);
	FragTrap &operator=(const FragTrap &other);
	~FragTrap(void);

	void highFivesGuys(void) const;
	void attack(const std::string &target);

  private:
	void _initAttrDefaultFrag(void);
};

std::ostream &operator<<(std::ostream &os, FragTrap const &fragTrap);