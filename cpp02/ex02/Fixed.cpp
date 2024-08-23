/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:25:35 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/08 14:56:59 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "external.hpp"

Fixed::Fixed(void)
	: _value(0)
{
	// std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const int num)
{
	// std::cout << "Int constructor called" << std::endl;
	this->setRawBits(Fixed::intToFixed(num));
}

Fixed::Fixed(const float num)
{
	// std::cout << "Float constructor called" << std::endl;
	this->setRawBits(Fixed::floatToFixed(num));
}

Fixed::Fixed(const Fixed &bluePrint)
{
	// std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(bluePrint.getRawBits());
	return ;
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed &Fixed::operator=(const Fixed &copyFrom)
{
	// std::cout << "Copy assignment operator called" << std::endl;
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
	// std::cout << "insertion operator overload called" << std::endl;
	os << fixed.toFloat();
	return (os);
}

bool Fixed::operator>(const Fixed &other) const
{
	// std::cout << "greater than operator overload called" << std::endl;
	return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const
{
	// std::cout << "smaller than operator overload called" << std::endl;
	return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const
{
	// std::cout << "smaller equal than operator overload called" << std::endl;
	return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const
{
	// std::cout << "greater equal than operator overload called" << std::endl;
	return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const
{
	// std::cout << "equal to operator overload called" << std::endl;
	return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const
{
	// std::cout << "unequal to operator overload called" << std::endl;
	return (this->getRawBits() != other.getRawBits());
}

Fixed &Fixed::operator++(void)
{
	// std::cout << "preincrement operator overload called" << std::endl;
	++this->_value;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	// std::cout << "postincrement operator overload called" << std::endl;
	Fixed	tmp(*this);

	this->_value++;
	return (tmp);
}

Fixed &Fixed::operator--(void)
{
	// std::cout << "predecrement operator overload called" << std::endl;
	--this->_value;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	// std::cout << "postdecrement operator overload called" << std::endl;
	Fixed	tmp(*this);

	this->_value--;
	return (tmp);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	// std::cout << "add operator overload called" << std::endl;
	return (newFixedFromRawBits(this->getRawBits() + other.getRawBits()));
}

Fixed Fixed::operator-(const Fixed &other) const
{
	// std::cout << "subtract operator overload called" << std::endl;
	return (newFixedFromRawBits(this->getRawBits() - other.getRawBits()));
}

Fixed Fixed::operator*(const Fixed &other) const
{
	// std::cout << "multiply operator overload called" << std::endl;
	int64_t product = static_cast<int64_t>(this->getRawBits())
		* other.getRawBits();
	return (newFixedFromRawBits(static_cast<int>(product
				/ this->_scalingFactor)));
}

Fixed Fixed::operator/(const Fixed &other) const
{
	// std::cout << "divide operator overload called" << std::endl;
	int64_t dividend = (static_cast<int64_t>(this->getRawBits())
			* this->_scalingFactor);
	return (newFixedFromRawBits(static_cast<int>(dividend
				/ other.getRawBits())));
}

const Fixed &Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	// std::cout << "const min member function called" << std::endl;
	return (fixed1 <= fixed2 ? fixed1 : fixed2);
}

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	// std::cout << "min member function called" << std::endl;
	return (fixed1 <= fixed2 ? fixed1 : fixed2);
}

const Fixed &Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	// std::cout << "const max member function called" << std::endl;
	return (fixed1 >= fixed2 ? fixed1 : fixed2);
}

Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	// std::cout << "max member function called" << std::endl;
	return (fixed1 >= fixed2 ? fixed1 : fixed2);
}

Fixed Fixed::newFixedFromRawBits(const int rawBits)
{
	Fixed	newFixed;

	newFixed = Fixed();
	newFixed.setRawBits(rawBits);
	return (newFixed);
}
