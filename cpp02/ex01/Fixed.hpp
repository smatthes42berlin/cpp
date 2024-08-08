/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:22:39 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/01 17:23:29 by smatthes         ###   ########.fr       */
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

	Fixed &operator=(const Fixed &copyFrom);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

	static int intToFixed(int value);
	static int fixedToInt(int value);
	static int floatToFixed(float value);
	static float fixedToFloat(int value);

  private:
	int _value;
	const static int _fractionalBits = 8;
	const static int _scalingFactor = 1 << Fixed::_fractionalBits;
};

std::ostream &operator<<(std::ostream &os, Fixed const &fixed);