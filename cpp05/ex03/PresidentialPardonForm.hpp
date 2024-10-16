/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:18:30 by smatthes          #+#    #+#             */
/*   Updated: 2024/10/16 10:18:43 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "external.hpp"

class PresidentialPardonForm : public AForm
{
  public:
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	~PresidentialPardonForm(void);

	void execute(Bureaucrat const &executor) const;

  private:
	PresidentialPardonForm(void);

	void execute_for_real() const;
};
