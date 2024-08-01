/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:25:35 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/01 13:11:08 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "external.hpp"

Fixed::Fixed(void) : _value(0)
{
	return ;
}

Fixed::Fixed(const int num)
{
	this->setRawBits(Fixed::intToFixed(num));
}

Fixed::Fixed(const float num)
{
	this->setRawBits(Fixed::floatToFixed(num));
}

Fixed::Fixed(const Fixed &bluePrint)
{
	this->setRawBits(bluePrint.getRawBits());
	return ;
}

Fixed::~Fixed(void)
{
	return ;
}

Fixed &Fixed::operator=(const Fixed &copyFrom)
{
	if (this == &copyFrom)
	{
		return (*this);
	}
	this->setRawBits(copyFrom.getRawBits());
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return (Fixed::fixedToFloat(this->getRawBits()));
}

int Fixed::toInt(void) const
{
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
	return (static_cast<int>(value * Fixed::_scalingFactor));
}

float Fixed::fixedToFloat(int value)
{
	return (static_cast<float>(value) / Fixed::_scalingFactor);
}

int	Fixed::getFractionPart(void) const
{
	return this->getRawBits() & 255;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toInt() << "." << fixed.getFractionPart();
	return (os);
}
