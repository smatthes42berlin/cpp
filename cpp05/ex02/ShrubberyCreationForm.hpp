/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:16:13 by smatthes          #+#    #+#             */
/*   Updated: 2024/10/16 10:03:56 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "external.hpp"

class ShrubberyCreationForm : public AForm
{
  public:
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	~ShrubberyCreationForm(void);

	void execute(Bureaucrat const &executor) const;

  private:
	ShrubberyCreationForm(void);

	void execute_for_real() const;
};

