/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:22:39 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/22 09:37:40 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "external.hpp"
#include "WrongAnimal.hpp"

#pragma once

class WrongCat: public WrongAnimal
{
  public:
	WrongCat(void);
	WrongCat(const WrongCat &other);
	WrongCat &operator=(const WrongCat &other);
	~WrongCat(void);

	void makeSound(void) const;
};
