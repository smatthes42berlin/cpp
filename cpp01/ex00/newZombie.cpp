/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes  <smatthes@student.42berlin>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:44:05 by smatthes          #+#    #+#             */
/*   Updated: 2024/07/21 09:45:41 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "external.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie *newZomb = new Zombie(name);
	return (newZomb);
}