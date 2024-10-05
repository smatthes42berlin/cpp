/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:52:06 by smatthes          #+#    #+#             */
/*   Updated: 2024/10/05 11:55:44 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "external.hpp"

ScalarConverter::ScalarConverter(void)
{
	std::cout << "<default constructor> ScalarConverter" << std::endl;
	return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	std::cout << "<copy constructor> ScalarConverter" << std::endl;
	(void)other;
	return ;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	std::cout << "<copy assignment operator> ScalarConverter" << std::endl;
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "<destructor> ScalarConverter" << std::endl;
	return ;
}

void ScalarConverter::convert(std::string literal)
{
	if (literal.length() == 0)
		throw ScalarConverter::EmptyInputException();
	if (ScalarConverter::isChar(literal))
		return (ScalarConverter::handle_char_literal(literal));
	if (ScalarConverter::isInt(literal))
		return (ScalarConverter::handle_int_literal(literal));
	if (ScalarConverter::isFloat(literal))
		return (ScalarConverter::handle_float_literal(literal));
	if (ScalarConverter::isDouble(literal))
		return (ScalarConverter::handle_double_literal(literal));
	throw ScalarConverter::UnknownCppLiteralException();
}

void ScalarConverter::handle_char_literal(std::string literal)
{
	char	c;

	c = ScalarConverter::convert_char(literal);
	ScalarConverter::print_char(c);
}

void ScalarConverter::handle_int_literal(std::string literal)
{
	int	i;

	i = ScalarConverter::convert_int(literal);
	ScalarConverter::print_int(i);
}

void ScalarConverter::handle_float_literal(std::string literal)
{
	float	f;

	f = ScalarConverter::convert_float(literal);
	ScalarConverter::print_float(f);
}

void ScalarConverter::handle_double_literal(std::string literal)
{
	double	d;

	d = ScalarConverter::convert_double(literal);
	ScalarConverter::print_double(d);
}

char ScalarConverter::convert_char(std::string literal)
{
	return (literal.length() == 1 ? literal[0] : literal[1]);
}

int ScalarConverter::convert_int(std::string literal)
{
	int	i;

	std::stringstream stst(literal);
	stst >> i;
	if (stst.fail())
	{
		throw ScalarConverter::ConversionFailException();
	}
	return (i);
}

float ScalarConverter::convert_float(std::string literal)
{
	float	f;

	std::stringstream stst(literal);
	if (literal == "nanf")
		f = std::numeric_limits<float>::quiet_NaN();
	else if (literal == "+inff")
		f = std::numeric_limits<float>::infinity();
	else if (literal == "-inff")
		f = -std::numeric_limits<float>::infinity();
	else
	{
		stst >> f;
		if (stst.fail())
			throw ScalarConverter::ConversionFailException();
	}
	return (f);
}

double ScalarConverter::convert_double(std::string literal)
{
	double	d;

	std::stringstream stst(literal);
	if (literal == "nan")
		d = std::numeric_limits<double>::quiet_NaN();
	else if (literal == "+inf")
		d = std::numeric_limits<double>::infinity();
	else if (literal == "-inf")
		d = -std::numeric_limits<double>::infinity();
	else
	{
		stst >> d;
		if (stst.fail())
			throw ScalarConverter::ConversionFailException();
	}
	return (d);
}

void ScalarConverter::print_char(char c)
{
	std::cout << "char: ";
	std::cout << "'" << c << "'";
	std::cout << std::endl;
	std::cout << "int: ";
	std::cout << static_cast<int>(c);
	std::cout << std::endl;
	std::cout << "float: ";
	std::cout << std::fixed << std::setprecision(1);
	std::cout << static_cast<float>(c) << "f";
	std::cout << std::endl;
	std::cout << "double: ";
	std::cout << static_cast<double>(c);
	std::cout << std::endl;
}

void ScalarConverter::print_int(int i)
{
	std::cout << "char: ";
	if (i < 0 || i > 127)
		std::cout << "impossible";
	else if (i < 32 || i > 126)
		std::cout << "not printable";
	else
		std::cout << "'" << static_cast<char>(i) << "'";
	std::cout << std::endl;
	std::cout << "int: ";
	std::cout << i;
	std::cout << std::endl;
	std::cout << "float: ";
	std::cout << std::fixed << std::setprecision(1);
	std::cout << static_cast<float>(i) << "f";
	std::cout << std::endl;
	std::cout << "double: ";
	std::cout << static_cast<double>(i);
	std::cout << std::endl;
}

void ScalarConverter::print_float(float f)
{
	std::cout << "char: ";
	if (ScalarConverter::is_nan(f) || ScalarConverter::is_inf(f) || f < 0
		|| f > 127)
		std::cout << "impossible";
	else if (f < 32 || f > 126)
		std::cout << "not printable";
	else
		std::cout << "'" << static_cast<char>(f) << "'";
	std::cout << std::endl;
	std::cout << "int: ";
	if (ScalarConverter::is_nan(f) || ScalarConverter::is_inf(f)
		|| f < static_cast<float>(INT_MIN) || f > static_cast<float>(INT_MAX))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(f);
	std::cout << std::endl;
	std::cout << "float: ";
	std::cout << std::fixed << std::setprecision(6);
	std::cout << f << "f";
	std::cout << std::endl;
	std::cout << std::fixed << std::setprecision(16);
	std::cout << "double: ";
	std::cout << static_cast<double>(f);
	std::cout << std::endl;
}

void ScalarConverter::print_double(double d)
{
	float	f;

	std::cout << "char: ";
	if (ScalarConverter::is_nan(d) || ScalarConverter::is_inf(d) || d < 0
		|| d > 127)
		std::cout << "impossible";
	else if (d < 32 || d > 126)
		std::cout << "not printable";
	else
		std::cout << "'" << static_cast<char>(d) << "'";
	std::cout << std::endl;
	std::cout << "int: ";
	if (ScalarConverter::is_nan(d) || ScalarConverter::is_inf(d)
		|| d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d);
	std::cout << std::endl;
	std::cout << std::fixed << std::setprecision(6);
	std::cout << "float: ";
	f = static_cast<float>(d);
	if (!ScalarConverter::is_inf(d) && (d < static_cast<double>(FLT_MIN)
			|| d > static_cast<double>(FLT_MAX)))
		std::cout << "impossible";
	else
		std::cout << f << "f";
	std::cout << std::endl;
	std::cout << std::fixed << std::setprecision(16);
	std::cout << "double: ";
	std::cout << d;
	std::cout << std::endl;
}

const char *ScalarConverter::UnknownCppLiteralException::what() const throw()
{
	return ("ScalarConverter: The literal you have entered is neither "
			"a char-, nor an int-, nor a float-, nor a double-literal");
}

const char *ScalarConverter::ConversionFailException::what() const throw()
{
	return ("ScalarConverter: The provided literal couldn't be "
			"converted to the belonging data type."
			"It is possibly too big or small or in the wrong format.");
}

const char *ScalarConverter::EmptyInputException::what() const throw()
{
	return ("ScalarConverter: Empty input provided."
			"Please enter a(n) char-, int-, float- or double-literal");
}

bool ScalarConverter::isChar(std::string literal)
{
	if (literal.length() == 3)
	{
		if (!std::isprint(literal[1]))
			return (false);
		if (literal[0] == '\'' && literal[2] == '\'')
			return (true);
	}
	if (literal.length() == 1)
	{
		if (std::isprint(literal[0]) && !std::isdigit(literal[0]))
			return (true);
	}
	return (false);
}

bool ScalarConverter::isInt(std::string literal)
{
	size_t	i;

	i = 0;
	if (literal[0] == '+' || literal[0] == '-')
		i++;
	if (i == literal.length())
		return (false);
	while (i < literal.length())
	{
		if (isdigit(literal[i]))
			i++;
		else
			return (false);
	}
	return (true);
}

bool ScalarConverter::isFloat(std::string literal)
{
	size_t	i;
	bool	one_dot_found;
	bool	digit_afer_dot_found;

	one_dot_found = false;
	digit_afer_dot_found = false;
	if (literal == "-inff")
		return (true);
	if (literal == "+inff")
		return (true);
	if (literal == "nanf")
		return (true);
	if (literal[literal.length() - 1] != 'f')
		return (false);
	i = 0;
	if (literal[0] == '+' || literal[0] == '-')
		i++;
	if (i == literal.length())
		return (false);
	if (!std::isdigit(literal[i]))
		return (false);
	while (i < literal.length() - 1)
	{
		if (isdigit(literal[i]))
		{
			if (one_dot_found)
				digit_afer_dot_found = true;
			i++;
		}
		else if (literal[i] == '.' && one_dot_found)
			return (false);
		else if (literal[i] == '.')
		{
			one_dot_found = true;
			i++;
		}
		else
			return (false);
	}
	if (!one_dot_found || !digit_afer_dot_found)
		return (false);
	return (true);
}

bool ScalarConverter::isDouble(std::string literal)
{
	size_t	i;
	bool	one_dot_found;
	bool	digit_afer_dot_found;

	one_dot_found = false;
	digit_afer_dot_found = false;
	if (literal == "-inf")
		return (true);
	if (literal == "+inf")
		return (true);
	if (literal == "nan")
		return (true);
	i = 0;
	if (literal[0] == '+' || literal[0] == '-')
		i++;
	if (i == literal.length())
		return (false);
	if (!std::isdigit(literal[i]))
		return (false);
	while (i < literal.length())
	{
		if (isdigit(literal[i]))
		{
			if (one_dot_found)
				digit_afer_dot_found = true;
			i++;
		}
		else if (literal[i] == '.' && one_dot_found)
			return (false);
		else if (literal[i] == '.')
		{
			one_dot_found = true;
			i++;
		}
		else
			return (false);
	}
	if (!one_dot_found || !digit_afer_dot_found)
		return (false);
	return (true);
}

bool ScalarConverter::is_nan(float f)
{
	return (f != f);
}

bool ScalarConverter::is_nan(double f)
{
	return (f != f);
}

bool ScalarConverter::is_inf(float f)
{
	return (f == std::numeric_limits<float>::infinity() || f ==
		-std::numeric_limits<float>::infinity());
}

bool ScalarConverter::is_inf(double d)
{
	return (d == std::numeric_limits<double>::infinity() || d ==
		-std::numeric_limits<double>::infinity());
}