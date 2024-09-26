/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:14:46 by smatthes          #+#    #+#             */
/*   Updated: 2024/09/26 10:56:58 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "external.hpp"

class Form;

class Bureaucrat
{
  public:
	Bureaucrat(void);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat(std::string name);
	Bureaucrat(std::string name, int grade);
	Bureaucrat &operator=(const Bureaucrat &other);
	virtual ~Bureaucrat(void);

	std::string get_name(void) const;
	int get_grade(void) const;

	void increment_grade(void);
	void decrement_grade(void);

	void signForm(Form &form);

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
	int _grade;

	void set_grade(int new_grade);
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat);
