/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:30:21 by smatthes          #+#    #+#             */
/*   Updated: 2024/10/16 13:57:11 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "external.hpp"

int	main(void)
{
	Intern					intern_1;
	ShrubberyCreationForm	*form_schrub;
	RobotomyRequestForm		*form_robot;
	PresidentialPardonForm	*form_pardon;


	Bureaucrat bur_powerful("bur_powerful", 1);
	form_schrub = reinterpret_cast<ShrubberyCreationForm *>(intern_1.makeForm("shrubbery creation",
				"you"));
	std::cout << *form_schrub << std::endl;
	bur_powerful.signForm(*form_schrub);
	bur_powerful.executeForm(*form_schrub);
	form_robot = reinterpret_cast<RobotomyRequestForm *>(intern_1.makeForm("robotomy request",
				"you"));
	std::cout << *form_robot << std::endl;
	bur_powerful.signForm(*form_robot);
	bur_powerful.executeForm(*form_robot);
	form_pardon = reinterpret_cast<PresidentialPardonForm *>(intern_1.makeForm("presidential pardon",
				"you"));
	std::cout << *form_pardon << std::endl;
	bur_powerful.signForm(*form_pardon);
	bur_powerful.executeForm(*form_pardon);

	try{
		intern_1.makeForm("unknown", "you");
	}
	catch(std::exception &err)
	{
		std::cerr << err.what() << std::endl;
	}

	delete					form_schrub;
	delete					form_robot;
	delete					form_pardon;

	return (0);
}
