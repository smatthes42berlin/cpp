/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:21:29 by smatthes          #+#    #+#             */
/*   Updated: 2024/07/25 14:21:09 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Test.hpp"
#include "external.hpp"

int	main(void)
{
	Test	ti1;
	bool	res;

	Test ti2(ti1);
	if (&ti1 == &ti2)
	{
		std::cout << "t1 == ti2";
	}
	else
	{
        std::cout << "not";
	}
    std::cout << std::endl;
}
