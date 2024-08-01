/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:22:39 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/01 12:00:47 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "external.hpp"

#pragma once

class Fixed
{
  public:
	Fixed(void);
	Fixed(const Fixed& bluePrint);
	~Fixed(void);
	
	Fixed& operator=(const Fixed& copyFrom);
	int getRawBits(void) const;
	void setRawBits(int const raw);

  private:
	int _value;
	const static int _fractionalBits = 8;
};
