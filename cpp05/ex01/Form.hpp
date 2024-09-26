/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:14:46 by smatthes          #+#    #+#             */
/*   Updated: 2024/09/26 11:07:24 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "external.hpp"
#include "Bureaucrat.hpp"

class Form
{
  public:
	Form(void);
	Form(const Form &other);
	Form(std::string name, int grade_to_sign, int grade_to_execute);
	Form &operator=(const Form &other);
	virtual ~Form(void);

	std::string get_name(void) const;
	int get_grade_to_sign(void) const;
	int get_grade_to_execute(void) const;
	bool get_is_signed(void) const;
	void beSigned(Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};

  private:
	const std::string _name;
	bool _is_signed;
	const int _grade_to_sign;
	const int _grade_to_execute;

	void set_is_signed(bool is_signed);
	bool check_grade(int grade);
};

std::ostream &operator<<(std::ostream &os, Form const &Form);
