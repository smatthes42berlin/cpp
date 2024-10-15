/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:51:56 by smatthes          #+#    #+#             */
/*   Updated: 2024/10/05 12:20:15 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "external.hpp"

class ScalarConverter
{
  public:
	static void convert(std::string literal);

	static bool isChar(std::string literal);
	static bool isInt(std::string literal);
	static bool isFloat(std::string literal);
	static bool isDouble(std::string literal);

	static void handle_char_literal(std::string literal);
	static void handle_int_literal(std::string literal);
	static void handle_float_literal(std::string literal);
	static void handle_double_literal(std::string literal);

	static char convert_char(std::string literal);
	static int convert_int(std::string literal);
	static float convert_float(std::string literal);
	static double convert_double(std::string literal);

	static void print_char(char c);
	static void print_int(int i);
	static void print_float(float f);
	static void print_double(double d);

	static bool is_nan(float f);
	static bool is_nan(double f);
	static bool is_inf(float f);
	static bool is_inf(double d);

	class UnknownCppLiteralException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};

	class ConversionFailException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};

	class EmptyInputException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};

  private:
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	virtual ~ScalarConverter(void);
};
