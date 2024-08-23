/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:22:39 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/23 17:39:55 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "external.hpp"

#pragma once

class Animal
{
  public:
	Animal(void);
	Animal(const Animal &other);
	Animal(std::string type);
	Animal &operator=(const Animal &other);
	virtual ~Animal(void);

	std::string get_type(void) const;
	void set_type(std::string new_type);

	virtual void makeSound(void) const;

  protected:
	std::string _type;

};
