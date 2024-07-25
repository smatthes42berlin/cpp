/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:16:45 by smatthes          #+#    #+#             */
/*   Updated: 2024/07/25 14:16:51 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Test.hpp"
#include "external.hpp"

Test::Test()
{
	std::cout << "Default Constructor called";
	std::cout << std::endl;
	return ;
}

Test::Test(int const n) : _foo(n)
{
	std::cout << "Numeric Constructor called";
	std::cout << std::endl;
	return ;
}

Test::Test(Test const &src)
{
	std::cout << "Copy Constructor called";
	std::cout << std::endl;
	*this = src;
	return ;
}

Test::~Test()
{
	
}

Test & Test::operator=(Test const & rhs){
	std::cout << "Assignment operator called";
	std::cout << std::endl;
    
    if(this != &rhs)
        this->_foo = rhs.getFoo();
    return *this;
}

int Test::getFoo() const
{
	return (this->_foo);
}
