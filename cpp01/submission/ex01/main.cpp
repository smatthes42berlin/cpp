/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes  <smatthes@student.42berlin>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:16:45 by smatthes          #+#    #+#             */
/*   Updated: 2024/07/21 10:23:20 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "external.hpp"
#include "functions.hpp"

int	main(void)
{
	int numZombies = 10;

	Zombie *zombies = zombieHorde(numZombies, "Steffen");

	for (int i = 0; i < numZombies; i++)
	{
		zombies[i].announce();
	}
	delete[] zombies;
	return (0);
}