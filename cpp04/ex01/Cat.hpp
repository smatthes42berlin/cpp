/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:22:39 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/22 09:37:40 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "external.hpp"
#include "Brain.hpp"

#pragma once

class Cat : public Animal
{
  public:
	Cat(void);
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	~Cat(void);

	void makeSound(void) const;

	Brain *getBrain() const;

  private:
	Brain *_brain;
};
