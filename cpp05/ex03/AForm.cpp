/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:16:01 by smatthes          #+#    #+#             */
/*   Updated: 2024/10/16 10:36:17 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "external.hpp"

AForm::AForm(void) : _name("default"), _is_signed(false), _grade_to_sign(75),
	_grade_to_execute(75)
{
	std::cout << "<default constructor> AForm" << std::endl;
	return ;
}
AForm::AForm(const std::string name, int grade_to_sign,
	int grade_to_execute) : _name(name), _is_signed(false),
	_grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
	this->check_grade(grade_to_sign);
	this->check_grade(grade_to_execute);
	std::cout << "<name grades constructor> AForm" << std::endl;
	return ;
}

AForm::AForm(std::string name, int grade_to_sign, int grade_to_execute,
	bool is_signed, std::string target) : _name(name), _is_signed(is_signed),
	_grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute),
	_target(target)

{
	this->check_grade(grade_to_sign);
	this->check_grade(grade_to_execute);
	std::cout << "<name grades target constructor> AForm" << std::endl;
	return ;
}

AForm::AForm(const AForm &other) : _name(other.get_name()),
	_is_signed(other.get_is_signed()),
	_grade_to_sign(other.get_grade_to_sign()),
	_grade_to_execute(other.get_grade_to_execute())
{
	std::cout << "<copy constructor> AForm" << std::endl;
	return ;
}

AForm &AForm::operator=(const AForm &other)
{
	std::cout << "<copy assignment operator> AForm" << std::endl;
	if (this != &other)
	{
		this->set_is_signed(other.get_is_signed());
		this->set_target(other.get_target());
	}
	return (*this);
}

AForm::~AForm(void)
{
	std::cout << "<destructor> AForm" << std::endl;
	return ;
}

std::string AForm::get_name(void) const
{
	return (this->_name);
}

int AForm::get_grade_to_sign(void) const
{
	return (this->_grade_to_sign);
}

int AForm::get_grade_to_execute(void) const
{
	return (this->_grade_to_execute);
}

bool AForm::get_is_signed(void) const
{
	return (this->_is_signed);
}

std::string AForm::get_target(void) const
{
	return (this->_target);
}

void AForm::set_is_signed(bool is_signed)
{
	this->_is_signed = is_signed;
}

void AForm::set_target(std::string target)
{
	this->_target = target;
}

bool AForm::check_grade(int grade)
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

void AForm::beSigned(Bureaucrat &bureaucrat)
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

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("AForm: Grade too high! It must be between 1 and 150.");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("AForm: Grade too low!");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("AForm: Form is not signed yet!");
}

bool AForm::check_can_be_executed(Bureaucrat const &bureaucrat) const
{
	if (!this->get_is_signed())
		throw FormNotSignedException();
	if (bureaucrat.get_grade() > this->get_grade_to_execute())
		throw Bureaucrat::BureaucratNotAuthorisedToExecuteForm();
	return (true);
}

std::ostream &operator<<(std::ostream &os, AForm const &AForm)
{
	os << std::endl;
	os << "*****AForm*****";
	os << std::endl;
	os << std::endl;
	os << "name: " << AForm.get_name();
	os << std::endl;
	os << "is_signed: " << AForm.get_is_signed();
	os << std::endl;
	os << "grade_to_sign: " << AForm.get_grade_to_sign();
	os << std::endl;
	os << "grade_to_execute: " << AForm.get_grade_to_execute();
	os << std::endl;
	os << "target: " << AForm.get_target();
	os << std::endl;
	os << std::endl;
	os << "*****ENDF*****";
	os << std::endl;
	return (os);
}
