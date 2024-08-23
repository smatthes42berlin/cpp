/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:30:21 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/23 18:52:03 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
// #include "Dog.hpp"
#include "external.hpp"

int	main(void)
{
	Cat	*C1 = new Cat();
	C1->getBrain()->fillWithOneIdea("1");
	Cat	*C2 = new Cat();
	C2->getBrain()->fillWithOneIdea("2");

	std::cout << C1->getBrain();
	std::cout << C2->getBrain();

	*C2 = *C1;

	std::cout << C2->getBrain();

	delete C1;
	delete C2;

	return (0);
}
