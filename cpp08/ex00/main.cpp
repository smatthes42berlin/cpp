/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:01:18 by smatthes          #+#    #+#             */
/*   Updated: 2024/10/06 12:19:56 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include "external.hpp"

template <typename T>
void	add_to_container(T &container)
{
	container.push_back(1);
	container.push_back(2);
	container.push_back(3);
	container.push_back(4);
	container.push_back(5);
}

template <typename T>
void	print_elem(T elem)
{
	std::cout << elem << " ";
}

template <typename T>
void	print_container(T container)
{
	std::for_each(container.begin(), container.end(),
			print_elem<typename T::value_type>);
	std::cout << std::endl;
}

int	main(void)
{
	std::vector<int> test_vec;
	std::deque<int> test_deque;
	std::list<int> test_list;
	add_to_container(test_vec);
	add_to_container(test_deque);
	add_to_container(test_list);
	print_container(test_vec);
	print_container(test_deque);
	print_container(test_list);
	std::cout << std::endl;
	std::cout << std::endl;
	try
	{
		std::cout << *easyfind(test_vec, 2);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;
	try
	{
		std::cout << *easyfind(test_deque, 6);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;
	try
	{
		std::cout << *easyfind(test_list, 5);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;
	return (0);
}
