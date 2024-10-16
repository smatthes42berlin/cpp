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

#include "A_Animal.hpp"
#include "Brain.hpp"
#include "external.hpp"

#pragma once

class Dog : public A_Animal
{
  public:
	Dog(void);
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	~Dog(void);

	void makeSound(void) const;

	Brain *getBrain() const;

  private:
	Brain *_brain;
};
