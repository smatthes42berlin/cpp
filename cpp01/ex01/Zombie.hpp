/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes  <smatthes@student.42berlin>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:16:45 by smatthes          #+#    #+#             */
/*   Updated: 2024/07/21 10:16:45 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "external.hpp"

#pragma once

class Zombie
{
  public:
	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);

	void announce(void) const;
	void setName(std::string name);
	std::string getName(void) const;

  private:
	std::string _name;
};
