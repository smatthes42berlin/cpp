/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:14:46 by smatthes          #+#    #+#             */
/*   Updated: 2024/09/05 10:35:14 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "external.hpp"

#pragma once

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

	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char *what() const throw()
		// put into cpp file
		// {
		// 	return ("Grade too high! It must be between 1 and 150.");
		// }
	};

	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char *what() const throw()
		// put into cpp file
		// {
		// 	return ("Grade too low! It must be between 1 and 150.");
		// }
	};

  private:
	const std::string _name;
	int _grade;

	void set_grade(int new_grade);
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat);
