/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SampleClass.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes  <smatthes@student.42berlin>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:33:01 by smatthes          #+#    #+#             */
/*   Updated: 2024/07/18 10:17:28 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SampleClass.hpp"
#include <iostream>
#include <string>


Sample::Sample()
{
	std::cout << "Constructor called" << std::endl;
	return ;
}

Sample::~Sample(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

void Sample::setFirstName(std::string first)
{
	this->firstName = first;
}
