/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:18:18 by smatthes          #+#    #+#             */
/*   Updated: 2024/10/16 10:35:40 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "external.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(75)
{
	std::cout << "<default constructor> Bureaucrat" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(75)
{
	std::cout << "<name constructor> Bureaucrat" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	this->set_grade(grade);
	std::cout << "<name & grade constructor> Bureaucrat" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other.get_name()),
	_grade(other.get_grade())
{
	std::cout << "<copy constructor> Bureaucrat" << std::endl;
	return ;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "<copy assignment operator> Bureaucrat" << std::endl;
	if (this == &other)
	{
		return (*this);
	}
	this->set_grade(other.get_grade());
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "<destructor> Bureaucrat" << std::endl;
	return ;
}

std::string Bureaucrat::get_name(void) const
{
	return (this->_name);
}

int Bureaucrat::get_grade(void) const
{
	return (this->_grade);
}

void Bureaucrat::set_grade(int new_grade)
{
	if (new_grade < 1)
		throw GradeTooHighException();
	if (new_grade > 150)
		throw GradeTooLowException();
	this->_grade = new_grade;
}

void Bureaucrat::increment_grade(void)
{
	this->set_grade(this->get_grade() - 1);
}

void Bureaucrat::decrement_grade(void)
{
	this->set_grade(this->get_grade() + 1);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat: Grade too high! It must be between 1 and 150.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat: Grade too low!");
}

const char *Bureaucrat::BureaucratNotAuthorisedToExecuteForm::what() const throw()
{
	return ("Bureaucrat: Grade too low! Bureaucrat not authorised to execute form!");
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->get_name();
		std::cout << " signed ";
		std::cout << form.get_name();
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->get_name();
		std::cout << " couldn't sign ";
		std::cout << form.get_name();
		std::cout << " because ";
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->get_name();
		std::cout << " executed ";
		std::cout << form.get_name();
		std::cout << "!";
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->get_name();
		std::cout << " couldn't execute ";
		std::cout << form.get_name();
		std::cout << " because ";
		std::cout << e.what() << std::endl;
	}
}




std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat)
{
	os << bureaucrat.get_name();
	os << ", bureaucrat grade ";
	os << bureaucrat.get_grade();
	os << "." << std::endl;
	return (os);
}
