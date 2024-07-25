/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes  <smatthes@student.42berlin>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:44:09 by smatthes          #+#    #+#             */
/*   Updated: 2024/07/21 10:12:41 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "external.hpp"

void	randomChump(std::string name)
{
	Zombie newZomb = Zombie(name);
	newZomb.announce();
	return ;
}