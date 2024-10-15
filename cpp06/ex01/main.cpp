/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:01:18 by smatthes          #+#    #+#             */
/*   Updated: 2024/10/05 12:47:50 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "external.hpp"

int	main(void)
{
	Data		point;
	Data		*ptr;
	uintptr_t	serialized;
	Data		*deserialized;

	point.x = 1;
	point.y = 2;
	point.z = 3;
	ptr = &point;
	serialized = Serializer::serialize(ptr);
	deserialized = Serializer::deserialize(serialized);
	std::cout << "org Data" << std::endl;
	std::cout << "x: " << ptr->x;
	std::cout << std::endl;
	std::cout << "y: " << ptr->y;
	std::cout << std::endl;
	std::cout << "z: " << ptr->z;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "uintptr_t: " << serialized << std::endl;
	std::cout << "uintptr_t hex: 0x" << std::hex << serialized;
	std::cout << std::endl;
	std::cout << "org pointer: " << ptr << std::endl;
	std::cout << "deserialized pointer: " << deserialized << std::endl;
	std::cout << std::endl;
	std::cout << "deserialized Data" << std::endl;
	std::cout << "x: " << deserialized->x;
	std::cout << std::endl;
	std::cout << "y: " << deserialized->y;
	std::cout << std::endl;
	std::cout << "z: " << deserialized->z;
	std::cout << std::endl;
	return (0);
}
