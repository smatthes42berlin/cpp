/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:30:21 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/02 16:26:21 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "external.hpp"

int	main(void)
{

	std::cout << "tests from subject" << std::endl
				<< std::endl;

	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	std::cout << "testing comparison operators" << std::endl
				<< std::endl;

	Fixed num1(1.1f);
	Fixed num2(2.1f);

	std::cout << num1 << " < " << num2 << " " << (num1 < num2) << std::endl;
	std::cout << num2 << " < " << num1 << " " << (num2 < num1) << std::endl;
	std::cout << std::endl;
	std::cout << num1 << " > " << num2 << " " << (num1 > num2) << std::endl;
	std::cout << num2 << " > " << num1 << " " << (num2 > num1) << std::endl;
	std::cout << std::endl;
	std::cout << num1 << " <= " << num2 << " " << (num1 <= num2) << std::endl;
	std::cout << num2 << " <= " << num1 << " " << (num2 <= num1) << std::endl;
	std::cout << num1 << " <= " << num1 << " " << (num1 <= num1) << std::endl;
	std::cout << std::endl;
	std::cout << num1 << " >= " << num2 << " " << (num1 >= num2) << std::endl;
	std::cout << num2 << " >= " << num1 << " " << (num2 >= num1) << std::endl;
	std::cout << num1 << " >= " << num1 << " " << (num1 >= num1) << std::endl;
	std::cout << std::endl
				<< std::endl;

	std::cout << "testing increments" << std::endl
				<< std::endl;

	Fixed num3(0);

	std::cout << "num3 " << num3 << std::endl;
	std::cout << "num3++ " << num3++ << std::endl;
	std::cout << "num3 " << num3 << std::endl;
	std::cout << std::endl;

	Fixed num4(0);

	std::cout << "num4 " << num4 << std::endl;
	std::cout << "num4-- " << num4-- << std::endl;
	std::cout << "num4 " << num4 << std::endl;
	std::cout << std::endl;

	Fixed num5(0);

	std::cout << "num5 " << num5 << std::endl;
	std::cout << "++num5 " << ++num5 << std::endl;
	std::cout << "num5 " << num5 << std::endl;
	std::cout << std::endl;

	Fixed num6(0);

	std::cout << "num6 " << num6 << std::endl;
	std::cout << "--num6 " << --num6 << std::endl;
	std::cout << "num6 " << num6 << std::endl;
	std::cout << std::endl
				<< std::endl;

	std::cout << "testing arithmitic operators" << std::endl
				<< std::endl;

	Fixed a1(5.5f);
	Fixed b1(3.2f);

	std::cout << a1 << " + " << b1 << " = " << (a1 + b1) << std::endl;
	std::cout << a1 << " - " << b1 << " = " << (a1 - b1) << std::endl;
	std::cout << a1 << " * " << b1 << " = " << (a1 * b1) << std::endl;
	std::cout << a1 << " / " << b1 << " = " << (a1 / b1) << std::endl;
	std::cout << std::endl
				<< std::endl;

	std::cout << "testing min max functions" << std::endl
				<< std::endl;

	Fixed aa(5.5f);
	Fixed bb(3.2f);

	std::cout << "aa =" << aa << std::endl;
	std::cout << "bb =" << bb << std::endl;
	std::cout << "min(aa,bb)"
				<< " = " << Fixed::min(aa, bb) << std::endl;
	std::cout << "min(bb,aa)"
				<< " = " << Fixed::min(bb, aa) << std::endl;
	std::cout << "max(aa,bb)"
				<< " = " << Fixed::max(aa, bb)
				<< std::endl;
	std::cout << "max(bb,aa)"
				<< " = " << Fixed::max(bb, aa)
				<< std::endl;
	std::cout << std::endl
				<< std::endl;

	return (0);
}