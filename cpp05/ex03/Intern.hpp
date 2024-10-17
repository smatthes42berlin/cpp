/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:17:39 by smatthes          #+#    #+#             */
/*   Updated: 2024/10/16 13:42:54 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include "external.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

class Intern
{
  public:
	Intern(void);
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	virtual ~Intern(void);

	AForm *makeForm(std::string form_name, std::string form_target) const;

	class InvalidFormRequestException : public std::exception
	{
		virtual const char *what() const throw();
	};

  private:
	AForm *makeShrubbery(std::string target) const;
	AForm *makePresidential(std::string target) const;
	AForm *makeRobotomy(std::string target) const;
};
