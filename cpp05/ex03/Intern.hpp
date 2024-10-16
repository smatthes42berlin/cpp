/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:17:39 by smatthes          #+#    #+#             */
/*   Updated: 2024/10/16 11:20:56 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include "external.hpp"

class Intern
{
  public:
	Intern(void);
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	virtual ~Intern(void);

	AForm *makeForm(std::string form_name, std::string form_target) const;
};
