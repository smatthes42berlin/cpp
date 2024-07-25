/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:16:45 by smatthes          #+#    #+#             */
/*   Updated: 2024/07/25 10:40:27 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	this->_numLevels = 4;
	this->_levels[0] = "DEBUG";
	this->_levels[1] = "INFO";
	this->_levels[2] = "WARNING";
	this->_levels[3] = "ERROR";
	this->_levels[4] = "default";
	this->_complaints[0] = &Harl::_debug;
	this->_complaints[1] = &Harl::_info;
	this->_complaints[2] = &Harl::_warning;
	this->_complaints[3] = &Harl::_error;
	this->_complaints[4] = &Harl::_default;
}
Harl::~Harl()
{
}

void Harl::complain(std::string level) const
{
	for (int i = 0; i < this->_numLevels; i++)
	{
		if (level == this->_levels[i])
		{
			(this->*_complaints[i])();
			return ;
		}
	}
	(this->*_complaints[this->_numLevels])();
	return ;
}

void Harl::_default() const
{
	std::cout << "[ Probably complaining about insignificant problems ]";
	std::cout << std::endl;
}

void Harl::_debug() const
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!";
	std::cout << std::endl;
}

void Harl::_info() const
{
	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn’t put enough bacon in my burger! If you did, ";
	std::cout << "I wouldn’t be asking for more!";
	std::cout << std::endl;
}

void Harl::_warning() const
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.";
	std::cout << std::endl;
}

void Harl::_error() const
{
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
}
