/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:01:18 by smatthes          #+#    #+#             */
/*   Updated: 2024/10/05 13:46:27 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "external.hpp"
#include "functions.hpp"

int	main(void)
{
	int		num;
	Base	*base;

	num = 10;
	for (int i = 0; i < num; i++)
	{
		std::cout << "*******One test case******" << std::endl;
		base = generate();
		std::cout <<std::endl;
		identify(base);
		identify(*base);
		delete (base);
		std::cout << "*******End******" << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		sleep(1);
	}
	return (0);
}
