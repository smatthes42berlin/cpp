/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:16:45 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/10 12:45:06 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "external.hpp"

class Test
{
  public:
	Test();
	Test(int value);
	~Test();

	int getValue() const;
	void show(void) const;

  private:
	int _value;
};

class Derived : public Test
{
  public:
	Derived(int value);
	// ~Derived();

	// int getValue() const;
	void show(void) const;

  private:
	// int _value;
};
