/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:22:39 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/23 17:39:55 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "external.hpp"

#pragma once

class A_Animal
{
  public:
	A_Animal(void);
	A_Animal(const A_Animal &other);
	A_Animal(std::string type);
	A_Animal &operator=(const A_Animal &other);
	virtual ~A_Animal(void);

	std::string get_type(void) const;
	void set_type(std::string new_type);

	virtual void makeSound(void) const = 0;

  protected:
	std::string _type;

};
