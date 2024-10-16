/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 08:58:51 by smatthes          #+#    #+#             */
/*   Updated: 2024/10/16 10:01:55 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "external.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm",
	145, 137, false, "default")
{
	std::cout << "<default constructor> ShrubberyCreationForm" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm",
	145, 137, false, target)
{
	std::cout << "<is_signed-target constructor> ShrubberyCreationForm" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other.get_name(),
	other.get_grade_to_sign(), other.get_grade_to_execute(),
	other.get_is_signed(), other.get_target())
{
	std::cout << "<copy constructor> ShrubberyCreationForm" << std::endl;
	return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "<copy assignment operator> ShrubberyCreationForm" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "<destructor> ShrubberyCreationForm" << std::endl;
	return ;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->check_can_be_executed(executor))
		this->execute_for_real();
}

void ShrubberyCreationForm::execute_for_real(void) const
{
	std::string suffix = "_shrubbery";
	std::string const out_file_name = this->get_target() + suffix;

	std::ofstream outfile(out_file_name.c_str());

	if (!outfile.is_open())
	{
		throw std::ios_base::failure("Error: Could not open the file.");
	}

	std::string simple_pine_tree = "    *\n"
									"   ***\n"
									"  *****\n"
									" *******\n"
									"*********\n"
									"   |||\n"
									"   |||\n";

	std::string layered_christmas_tree = "      *\n"
											"     ***\n"
											"    *****\n"
											"   *******\n"
											"  *********\n"
											"     ***\n"
											"    *****\n"
											"   *******\n"
											"  *********\n"
											"     ***\n"
											"    *****\n"
											"   *******\n"
											"  *********\n"
											"     |||\n"
											"     |||\n";

	std::string full_tree = "       *\n"
							"      ***\n"
							"     *****\n"
							"    *******\n"
							"   *********\n"
							"  ***********\n"
							" *************\n"
							"***************\n"
							"      |||\n"
							"      |||\n";

	std::string symmetric_tree = "       A\n"
									"      AAA\n"
									"     AAAAA\n"
									"    AAAAAAA\n"
									"   AAAAAAAAA\n"
									"      |||\n"
									"      |||\n";

	std::string minimalist_tree = "   ^\n"
									"  ^^^\n"
									" ^^^^^\n"
									"^^^^^^^\n"
									"   |\n";

	std::string fancy_tree = "       __/\\__\n"
								"      _/ *  *\\_\n"
								"     / * *  * *\\\n"
								"    /  *  *  *  \\\n"
								"   /_____________\\\n"
								"      ||||||||\n"
								"      ||||||||\n";

	std::string tall_tree = "       *\n"
							"      ***\n"
							"     *****\n"
							"    *******\n"
							"   *********\n"
							"  ***********\n"
							" *************\n"
							"***************\n"
							"       ||\n"
							"       ||\n"
							"       ||\n"
							"       ||\n";

	outfile << simple_pine_tree;
	outfile << std::endl;
	outfile << layered_christmas_tree;
	outfile << std::endl;
	outfile << full_tree;
	outfile << std::endl;
	outfile << symmetric_tree;
	outfile << std::endl;
	outfile << minimalist_tree;
	outfile << std::endl;
	outfile << fancy_tree;
	outfile << std::endl;
	outfile << tall_tree;
	outfile << std::endl;
	outfile.close();
}
