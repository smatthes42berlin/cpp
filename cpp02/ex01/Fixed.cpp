/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:25:35 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/08 13:21:20 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "external.hpp"

Fixed::Fixed(void)
	: _value(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(Fixed::intToFixed(num));
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(Fixed::floatToFixed(num));
}

Fixed::Fixed(const Fixed &bluePrint)
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(bluePrint.getRawBits());
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed &Fixed::operator=(const Fixed &copyFrom)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &copyFrom)
	{
		return (*this);
	}
	this->setRawBits(copyFrom.getRawBits());
	return (*this);
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	// std::cout << "toFloat member function called" << std::endl;
	return (Fixed::fixedToFloat(this->getRawBits()));
}

int Fixed::toInt(void) const
{
	// std::cout << "toInt member function called" << std::endl;
	return (Fixed::fixedToInt(this->getRawBits()));
}

int Fixed::intToFixed(int value)
{
	return (value * Fixed::_scalingFactor);
}

int Fixed::fixedToInt(int value)
{
	return (value / Fixed::_scalingFactor);
}

int Fixed::floatToFixed(float value)
{
	return (static_cast<int>(roundf(value * Fixed::_scalingFactor)));
}

float Fixed::fixedToFloat(int value)
{
	return (static_cast<float>(value) / Fixed::_scalingFactor);
}

std::ostream &operator<<(std::ostream &os, Fixed const &fixed)
{
	// std::cout << "insertiodenizozd on operator overload called" << std::endl;
	os << fixed.toFloat();
	return (os);
}
