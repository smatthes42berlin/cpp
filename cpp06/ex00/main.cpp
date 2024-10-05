/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:01:18 by smatthes          #+#    #+#             */
/*   Updated: 2024/10/05 11:58:32 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "external.hpp"

void	test_type(void);
void	test_type_char(void);
void	test_type_int(void);
void	test_type_float(void);
void	test_type_double(void);
void	test_type_unknown(void);
void	test_helper(std::string test_str, std::string supposed_type);

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./conversion <literal>" << std::endl;
		return (1);
	}
	std::string const input(argv[1]);
	try
	{
		ScalarConverter::convert(input);
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}

void	test_type(void)
{
	test_type_char();
	test_type_int();
	test_type_float();
	test_type_double();
	test_type_unknown();
}

void	test_helper(std::string test_str, std::string supposed_type)
{
	std::cout << supposed_type << "  " << test_str << " = ";
	try
	{
		std::cout << test_str << " = " << supposed_type;
		std::cout << std::endl;
		ScalarConverter::convert(test_str);
	}
	catch (const std::runtime_error &e)
	{
		std::cout << "Caught an exception: " << e.what() << std::endl;
	}
}

void	test_type_char(void)
{
	std::cout << std::endl;
	std::cout << "*********CHARS********";
	std::cout << std::endl;
	test_helper("a", "char");
	test_helper("'9'", "char");
	test_helper("z", "char");
	test_helper(" ", "char");
	test_helper("' '", "char");
	test_helper("~", "char");
	test_helper("'~'", "char");
	test_helper("'a'", "char");
	test_helper("'", "char");
	test_helper("\"", "char");
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}

void	test_type_int(void)
{
	std::cout << "*********INT********";
	std::cout << std::endl;
	test_helper("1", "int");
	test_helper("0", "int");
	test_helper("+1", "int");
	test_helper("-1", "int");
	test_helper("+0", "int");
	test_helper("-0", "int");
	// test_helper("12345678901234567890", "int");
	// test_helper("+12345678901234567890", "int");
	// test_helper("-12345678901234567890", "int");
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}

void	test_type_float(void)
{
	std::cout << "*********Float********";
	std::cout << std::endl;
	test_helper("-inff", "float");
	test_helper("+inff", "float");
	test_helper("nanf", "float");
	test_helper("0.0f", "float");
	test_helper("-0.0f", "float");
	test_helper("+0.0f", "float");
	test_helper("+4.2f", "float");
	test_helper("-4.2f", "float");
	test_helper("4.2f", "float");
	test_helper("1234567890123456789012345678910.1234567890123456789012345678910f",
				"float");
	test_helper("+1234567890123456789012345678910.1234567890123456789012345678910f",
				"float");
	test_helper("-1234567890123456789012345678910.1234567890123456789012345678910f",
				"float");
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}

void	test_type_double(void)
{
	std::cout << "*********Double********";
	std::cout << std::endl;
	test_helper("-inf", "double");
	test_helper("+inf", "double");
	test_helper("nan", "double");
	test_helper("0.0", "double");
	test_helper("-0.0", "double");
	test_helper("+0.0", "double");
	test_helper("+4.2", "double");
	test_helper("-4.2", "double");
	test_helper("4.2", "double");
	test_helper("1234567890123456789012345678910.1234567890123456789012345678910",
				"double");
	test_helper("+1234567890123456789012345678910.1234567890123456789012345678910",
				"double");
	test_helper("-1234567890123456789012345678910.1234567890123456789012345678910",
				"double");
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}

void	test_type_unknown(void)
{
	std::cout << "*********UNKNOWN********";
	std::cout << std::endl;
	test_helper("abc", "unknown");
	test_helper("'a''b'", "unknown");
	test_helper("''", "unknown");
	test_helper("+-0", "unknown");
	test_helper("+-1", "unknown");
	test_helper("--0", "unknown");
	test_helper("--1", "unknown");
	test_helper("++0", "unknown");
	test_helper("++1", "unknown");
	test_helper("-0..f", "unknown");
	test_helper("-f", "unknown");
	test_helper("+f", "unknown");
	test_helper("0.0ff", "unknown");
	test_helper("4.f", "unknown");
	test_helper("4f", "unknown");
	test_helper("0f", "unknown");
	test_helper(".0f", "unknown");
	test_helper("-.1f", "unknown");
	test_helper("+.1f", "unknown");
	test_helper("0.f", "unknown");
	test_helper("-0.f", "unknown");
	test_helper("-0..", "unknown");
	test_helper("-", "unknown");
	test_helper("+", "unknown");
	test_helper(".0", "unknown");
	test_helper("4.", "unknown");
	test_helper("0.", "unknown");
	test_helper("-.0", "unknown");
	test_helper("+.0", "unknown");
	test_helper(".0", "unknown");
	test_helper("", "unknown");
}
