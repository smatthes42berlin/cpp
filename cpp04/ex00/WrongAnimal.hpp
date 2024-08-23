/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:22:39 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/23 17:39:55 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "external.hpp"

#pragma once

class WrongAnimal
{
  public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal(std::string type);
	WrongAnimal &operator=(const WrongAnimal &other);
	~WrongAnimal(void);

	std::string get_type(void) const;
	void set_type(std::string new_type);

	void makeSound(void) const;

  protected:
	std::string _type;

};
