/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:16:13 by smatthes          #+#    #+#             */
/*   Updated: 2024/10/16 11:31:15 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include "external.hpp"

class AForm
{
  public:
	AForm(void);
	AForm(const AForm &other);
	AForm(std::string name, int grade_to_sign, int grade_to_execute);
	AForm(std::string name, int grade_to_sign, int grade_to_execute,
		bool is_signed, std::string target);
	AForm &operator=(const AForm &other);
	virtual ~AForm(void);

	virtual void execute(Bureaucrat const &bureaucrat) const = 0;

	std::string get_name(void) const;
	int get_grade_to_sign(void) const;
	int get_grade_to_execute(void) const;
	bool get_is_signed(void) const;
	std::string get_target(void) const;
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

	class FormNotSignedException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};

  protected:
	bool check_can_be_executed(Bureaucrat const &bureaucrat) const;
	void set_is_signed(bool is_signed);
	void set_target(std::string target);

  private:
	const std::string _name;
	bool _is_signed;
	const int _grade_to_sign;
	const int _grade_to_execute;
	std::string _target;

	bool check_grade(int grade);
};

std::ostream &operator<<(std::ostream &os, AForm const &AForm);
