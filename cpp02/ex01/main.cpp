/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:30:21 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/01 13:15:43 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "external.hpp"

int	main(void)
{
	Fixed num0 = Fixed(0);
	Fixed num1 = Fixed(1);
	Fixed num2 = Fixed(1.01f);

	std::cout << "num0 = " << num0.getRawBits() << std::endl;
	std::cout << "num1 = " << num1.getRawBits() << std::endl;
	std::cout << "num2 = " << num2.getRawBits() << std::endl;



	float test = 8.253; 
	Fixed fixedPoint = Fixed(test); 

	std::cout << fixedPoint.getFractionPart() << std::endl;
	std::cout << fixedPoint.toInt() << std::endl;

	return 0;


	

	return (0);
}