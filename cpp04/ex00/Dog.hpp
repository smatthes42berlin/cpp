/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:22:39 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/22 09:37:40 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "external.hpp"
#include "Animal.hpp"

#pragma once

class Dog: public Animal
{
  public:
	Dog(void);
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	~Dog(void);

	void makeSound(void) const;

};
