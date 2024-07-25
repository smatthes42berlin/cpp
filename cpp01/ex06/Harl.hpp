/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:16:45 by smatthes          #+#    #+#             */
/*   Updated: 2024/07/25 10:36:51 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "external.hpp"

#pragma once

class Harl
{
  public:
	Harl();
	~Harl();

	void complain(std::string level) const;

  private:

	int _numLevels;
	void (Harl::*_complaints[5])(void) const;
	std::string _levels[5];	
	void _debug() const;
	void _info() const;
	void _warning() const;
	void _error() const;
	void _default() const;
};
