/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:16:45 by smatthes          #+#    #+#             */
/*   Updated: 2024/07/21 14:25:19 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "external.hpp"

#pragma once

class HumanA
{
  public:
	HumanA(std::string name, Weapon &giveWeapon);
	~HumanA(void);

	void attack(void) const;

  private:
	std::string _name;
	Weapon &_weapon;
};
