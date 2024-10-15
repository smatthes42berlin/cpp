/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:52:06 by smatthes          #+#    #+#             */
/*   Updated: 2024/10/05 12:34:38 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "external.hpp"

Serializer::Serializer(void)
{
	std::cout << "<default constructor> Serializer" << std::endl;
	return ;
}

Serializer::Serializer(const Serializer &other)
{
	std::cout << "<copy constructor> Serializer" << std::endl;
	(void)other;
	return ;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	std::cout << "<copy assignment operator> Serializer" << std::endl;
	(void)other;
	return (*this);
}

Serializer::~Serializer(void)
{
	std::cout << "<destructor> Serializer" << std::endl;
	return ;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
	
}
