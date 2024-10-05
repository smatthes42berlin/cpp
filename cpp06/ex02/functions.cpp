/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:12:19 by smatthes          #+#    #+#             */
/*   Updated: 2024/10/05 13:45:02 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include "external.hpp"
#include "functions.hpp"

Base	*generate(void)
{
	int	randomValue;

	std::srand(static_cast<unsigned>(std::time(0)));
	randomValue = std::rand() % 3;
	switch (randomValue)
	{
	case 0:
		std::cout << "Instantiating A" << std::endl;
		return (new A());
	case 1:
		std::cout << "Instantiating B" << std::endl;
		return (new B());
	case 2:
		std::cout << "Instantiating C" << std::endl;
		return (new C());
	default:
		return (NULL);
	}
}

void	identify(Base *p)
{
	std::cout << "Identifying as pointer" << std::endl;
	if (dynamic_cast<A *>(p))
		std::cout << "Instance of A";
	else if (dynamic_cast<B *>(p))
		std::cout
			<< "Instance of B";
	else if (dynamic_cast<C *>(p))
		std::cout
			<< "Instance of C";
	else
		std::cout
			<< "No Instance of A, B or C";
	std::cout << std::endl;
	std::cout << std::endl;
}

void	identify(Base &p)
{
	std::cout << "Identifying as reference" << std::endl;
	try
	{
		dynamic_cast<A &>(p);
		std::cout << "Instance of A" << std::endl;
		return ;
	}
	catch (std::exception const &e)
	{
		std::cout << "Its not A " << e.what() << std::endl;
	}
	try
	{
		dynamic_cast<B &>(p);
		std::cout << "Instance of B" << std::endl;
		return ;
	}
	catch (std::exception const &e)
	{
		std::cout << "Its not B " << e.what() << std::endl;
	}
	try
	{
		dynamic_cast<C &>(p);
		std::cout << "Instance of C" << std::endl;
		return ;
	}
	catch (std::exception const &e)
	{
		std::cout << "Its not C " << e.what() << std::endl;
	}
}
