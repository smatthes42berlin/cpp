/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:22:39 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/02 15:45:25 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "external.hpp"

#pragma once

class Fixed
{
  public:
	Fixed(void);
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed &bluePrint);
	~Fixed(void);

	static Fixed newFixedFromRawBits(const int rawBits);
	static int intToFixed(int value);
	static int fixedToInt(int value);
	static int floatToFixed(float value);
	static float fixedToFloat(int value);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

	Fixed &operator=(const Fixed &copyFrom);
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;
	bool operator>(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;
	Fixed &operator++(void);
	Fixed operator++(int);
	Fixed &operator--(void);
	Fixed operator--(int);
	static const Fixed &min(const Fixed &fixed1, const Fixed &fixed2);
	static const Fixed &max(const Fixed &fixed1, const Fixed &fixed2);
	static Fixed &min(Fixed &fixed1, Fixed &fixed2);
	static Fixed &max(Fixed &fixed1, Fixed &fixed2);

  private:
	int _value;
	const static int _fractionalBits = 8;
	const static int _scalingFactor = 1 << Fixed::_fractionalBits;
};

std::ostream &operator<<(std::ostream &os, Fixed const &fixed);