/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:58:33 by smatthes          #+#    #+#             */
/*   Updated: 2024/09/26 11:08:12 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "external.hpp"

Form::Form(void) : _name("default"), _is_signed(false), _grade_to_sign(75),
	_grade_to_execute(75)
{
	std::cout << "<default constructor> Form" << std::endl;
	return ;
}
Form::Form(const std::string name, int grade_to_sign,
	int grade_to_execute) : _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
	this->check_grade(grade_to_sign);
	this->check_grade(grade_to_execute);
	std::cout << "<name grades constructor> Form" << std::endl;
	return ;
}

Form::Form(const Form &other) : _name(other.get_name()),
	_is_signed(other.get_is_signed()),
	_grade_to_sign(other.get_grade_to_sign()),
	_grade_to_execute(other.get_grade_to_execute())
{
	std::cout << "<copy constructor> Form" << std::endl;
	return ;
}

Form &Form::operator=(const Form &other)
{
	std::cout << "<copy assignment operator> Form" << std::endl;
	if (this == &other)
	{
		return (*this);
	}
	this->set_is_signed(other.get_is_signed());
	return (*this);
}

Form::~Form(void)
{
	std::cout << "<destructor> Form" << std::endl;
	return ;
}

std::string Form::get_name(void) const
{
	return (this->_name);
}

int Form::get_grade_to_sign(void) const
{
	return (this->_grade_to_sign);
}

int Form::get_grade_to_execute(void) const
{
	return (this->_grade_to_execute);
}

bool Form::get_is_signed(void) const
{
	return (this->_is_signed);
}

void Form::set_is_signed(bool is_signed)
{
	this->_is_signed = is_signed;
}

bool Form::check_grade(int grade)
{
	if (grade < 1)
	{
		throw GradeTooHighException();
		return (false);
	}
	if (grade > 150)
	{
		throw GradeTooLowException();
		return (false);
	}
	return (true);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (this->get_grade_to_sign() >= bureaucrat.get_grade())
	{
		this->set_is_signed(true);
	}
	else
	{
		throw GradeTooLowException();
	}
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form: Grade too high! It must be between 1 and 150.");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form: Grade too low! It must be between 1 and 150.");
}

std::ostream &operator<<(std::ostream &os, Form const &Form)
{
	os << std::endl;
	os << "*****FORM*****";
	os << std::endl;
	os << std::endl;
	os << "name: " << Form.get_name();
	os << std::endl;
	os << "is_signed: " << Form.get_is_signed();
	os << std::endl;
	os << "grade_to_sign: " << Form.get_grade_to_sign();
	os << std::endl;
	os << "grade_to_execute: " << Form.get_grade_to_execute();
	os << std::endl;
	os << std::endl;
	os << "*****ENDF*****";
	os << std::endl;
	return (os);
}
