/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:22:39 by smatthes          #+#    #+#             */
/*   Updated: 2024/08/22 09:37:40 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A_Animal.hpp"
#include "external.hpp"

#pragma once

class Brain
{
  public:
	Brain(void);
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain(void);

	std::string getIdea(int index) const;
	void setIdea(int index, std::string idea);

	void fillWithOneIdea(std::string idea);

  private:
	std::string _ideas[100];
};

std::ostream &operator<<(std::ostream &os, Brain const &brain);
