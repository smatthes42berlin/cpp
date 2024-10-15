/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:01:18 by smatthes          #+#    #+#             */
/*   Updated: 2024/10/05 17:19:40 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "external.hpp"
#include "iter.hpp"

int	main(void)
{
	int		arr_i[] ={0, 1, 2, 3, 4, 5};
	float	arr_f[] =  {0.1, 1.2, 2.3, 3.4};
	char	arr_c[] = {'a', 'b', 'c', 'd', 'e'};
	int		arr_i_len;
	int		arr_f_len;
	int		arr_c_len;
	int		arr_s_len;

	std::string arr_s[] = {"john", "jane", "doe"};
	arr_i_len = sizeof(arr_i) / sizeof(arr_i[0]);
	arr_f_len = 4;
	arr_c_len = sizeof(arr_c) / sizeof(arr_c[0]);
	arr_s_len = 3;
	iter(arr_i, arr_i_len, print<int>);
	std::cout << std::endl;
	iter(arr_i, arr_i_len, increment<int>);
	std::cout << std::endl;
	iter(arr_i, arr_i_len, print<int>);
	std::cout << std::endl
				<< std::endl;
	iter(arr_f, arr_f_len, print<float>);
	std::cout << std::endl;
	iter(arr_f, arr_f_len, increment<float>);
	std::cout << std::endl;
	iter(arr_f, arr_f_len, print<float>);
	std::cout << std::endl
				<< std::endl;
	iter(arr_c, arr_c_len, print<char>);
	std::cout << std::endl;
	iter(arr_c, arr_c_len, increment<char>);
	std::cout << std::endl;
	iter(arr_c, arr_c_len, print<char>);
	std::cout << std::endl
				<< std::endl;
	iter(arr_s, arr_s_len, print<std::string>);
	std::cout << std::endl;
	return (0);
}
