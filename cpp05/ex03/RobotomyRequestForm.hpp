/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:03:33 by smatthes          #+#    #+#             */
/*   Updated: 2024/10/16 10:04:00 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "external.hpp"

class RobotomyRequestForm : public AForm
{
  public:
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	~RobotomyRequestForm(void);

	void execute(Bureaucrat const &executor) const;

  private:
	RobotomyRequestForm(void);

	void execute_for_real() const;
};

