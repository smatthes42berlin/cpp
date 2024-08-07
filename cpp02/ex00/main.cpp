/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:30:21 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/01 12:18:26 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "external.hpp"

int	main(void)
{
	std::cout << std::endl << std::endl;
	std::cout << "running test from subject";
	std::cout << std::endl << std::endl;

	Fixed a;
	Fixed b(a);
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	std::cout << std::endl << std::endl;
	std::cout << "running my test";
	std::cout << std::endl << std::endl;


	Fixed num1 = Fixed();
	Fixed num2 = Fixed();

	num1.setRawBits(1);
	num2.setRawBits(2);

	Fixed num3 = Fixed(num2);
	num1 = num2;

	std::cout << "num1 = " << num1.getRawBits() << std::endl;
	std::cout << "num2 = " << num2.getRawBits() << std::endl;
	std::cout << "num3 = " << num3.getRawBits() << std::endl;

	return (0);
}