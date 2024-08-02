/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:25:35 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/02 15:56:20 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "external.hpp"

Fixed::Fixed(void)
	: _value(0)
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
	return (static_cast<int>(roundf(value * Fixed::_scalingFactor)));
}

float Fixed::fixedToFloat(int value)
{
	return (static_cast<float>(value) / Fixed::_scalingFactor);
}

std::ostream &operator<<(std::ostream &os, Fixed const &fixed)
{
	os << fixed.toFloat();
	return (os);
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->getRawBits() != other.getRawBits());
}

Fixed &Fixed::operator++(void)
{
	++this->_value;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	tmp;

	tmp = this->_value++;
	return (tmp);
}

Fixed &Fixed::operator--(void)
{
	--this->_value;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed	tmp;

	tmp = this->_value--;
	return (tmp);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	return (newFixedFromRawBits(this->getRawBits() + other.getRawBits()));
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return (newFixedFromRawBits(this->getRawBits() - other.getRawBits()));
}

Fixed Fixed::operator*(const Fixed &other) const
{
	int64_t product = static_cast<int64_t>(this->getRawBits())
		* other.getRawBits();
	return (newFixedFromRawBits(static_cast<int>(product
				/ this->_scalingFactor)));
}

Fixed Fixed::operator/(const Fixed &other) const
{
	int64_t dividend = (static_cast<int64_t>(this->getRawBits())
			* this->_scalingFactor);
	return (newFixedFromRawBits(static_cast<int>(dividend
				/ other.getRawBits())));
}

const Fixed &Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1 <= fixed2 ? fixed1 : fixed2);
}

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	return (fixed1 <= fixed2 ? fixed1 : fixed2);
}

const Fixed &Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1 >= fixed2 ? fixed1 : fixed2);
}

Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	return (fixed1 >= fixed2 ? fixed1 : fixed2);
}

Fixed Fixed::newFixedFromRawBits(const int rawBits)
{
	Fixed	newFixed;

	newFixed = Fixed();
	newFixed.setRawBits(rawBits);
	return (newFixed);
}
