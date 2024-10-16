/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:30:21 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/30 16:48:23 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A_Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
	#include "external.hpp"

void	runTestsSubject(void);
void	runMyTests(void);

int	main(void)
{
	// A_Animal test; 
	runMyTests();
	runTestsSubject();
	return (0);
}

void	runMyTests(void)
{
	Cat		*C1;
	Cat		*C2;

	C1 = new Cat();
	C1->getBrain()->fillWithOneIdea("1");
	C2 = new Cat();
	C2->getBrain()->fillWithOneIdea("2");
	std::cout << *(C1->getBrain());
	std::cout << *(C2->getBrain());
	*C2 = *C1;
	std::cout << *(C2->getBrain());
	delete	C1;
	delete	C2;
}

void	runTestsSubject(void)
{
	int				i;
	A_Animal			*animals[100];
	const A_Animal	*an1 = new Dog();
	const A_Animal	*an2 = new Cat();
	delete			an1;
	delete			an2;

	for (i = 0; i < 50; i++)
	{
		std::cout << i << std::endl;
		animals[i] = new Dog();
	}
	for (; i < 100; i++)
	{
		std::cout << i << std::endl;
		animals[i] = new Cat();
	}
	for (i = 0; i < 100; i++)
	{
		delete animals[i];
	}
}
