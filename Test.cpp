/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:16:45 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/10 12:45:41 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Test.hpp"
#include "external.hpp"

Test::Test()
{
	std::cout << "Test Default Constructor called";
	std::cout << std::endl;
	return ;
}

Derived::Derived(int value): Test(value)
{
	std::cout << "Derived Default Constructor called";
	std::cout << std::endl;
	return ;
}

Test::Test(int value): _value(value)
{
	std::cout << "Test Int Constructor called";
	std::cout << std::endl;
	return ;
}

Test::~Test()
{
	std::cout << "Test Destructor called";
	std::cout << std::endl;
	return ;
}

void Derived::show(void) const
{
	std::cout << "Derived class show method" << std::endl;
}

void Test::show(void) const
{
	std::cout << "Base class show method" << std::endl;
}

int Test::getValue() const
{
	return (this->_value);
}
