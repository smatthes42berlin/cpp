/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:52:06 by smatthes          #+#    #+#             */
/*   Updated: 2024/10/17 09:57:30 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "external.hpp"

RPN::RPN(void)
	: rpnExpression("")
{
	return ;
}

RPN::RPN(std::string curRpnExpression)
	: rpnExpression(curRpnExpression)
{
	return ;
}

RPN::RPN(const RPN &other)
{
	this->rpnExpression = other.rpnExpression;
	this->stack = other.stack;
	return ;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		this->rpnExpression = other.rpnExpression;
		this->stack = other.stack;
	}
	return (*this);
}

RPN::~RPN(void)
{
	return ;
}

void RPN::calc(void)
{
	this->rpnExpression = this->trim(this->rpnExpression);
	this->rpnExpression = this->ensureOnlyOneConsecutiveWs(this->rpnExpression);
	if (this->rpnExpression.length() == 0)
	{
		this->printError();
		return ;
	}
	std::string curToken = "";
	for (std::string::const_iterator it = this->rpnExpression.begin(); it != this->rpnExpression.end(); ++it)
	{
		if (std::isspace(*it) && curToken.length() > 0)
		{
			if (!this->processToken(curToken))
				return ;
			curToken = "";
		}
		else
		{
			curToken += *it;
		}
	}
	if (!this->processToken(curToken))
	{
		return ;
	}
	if (this->stack.size() != 1)
	{
		this->printError();
		return ;
	}
	else
		std::cout << this->stack.top();
	return ;
}

bool RPN::processToken(std::string curToken)
{
	if (curToken.length() == 1 && (curToken[0] == '+' || curToken[0] == '-'
			|| curToken[0] == '*' || curToken[0] == '/'))
		return (this->processOperator(curToken));
	if (curToken.length() == 1 && std::isdigit(curToken[0]))
		return (this->processOperand(curToken));
	if (curToken.length() == 2 && curToken[0] == '-'
		&& std::isdigit(curToken[1]))
		return (this->processOperand(curToken));
	return (this->printError());
}

bool RPN::processOperator(std::string curToken)
{
	float	val1;
	float	val2;
	float	res;

	if (this->stack.size() < 2)
		return (this->printError());
	val1 = this->stack.top();
	this->stack.pop();
	val2 = this->stack.top();
	this->stack.pop();
	if (curToken[0] == '+')
	{
		res = val2 + val1;
		this->stack.push(res);
	}
	if (curToken[0] == '-')
	{
		res = val2 - val1;
		this->stack.push(res);
	}
	if (curToken[0] == '*')
	{
		res = val2 * val1;
		this->stack.push(res);
	}
	if (curToken[0] == '/')
	{
		res = val2 / val1;
		this->stack.push(res);
	}
	return (true);
}

bool RPN::processOperand(std::string curToken)
{
	float	value;

	std::stringstream ss(curToken);
	ss >> value;
	if (ss.fail() || !ss.eof())
	{
		return (this->printError());
	}
	this->stack.push(value);
	return (true);
}

bool RPN::printError()
{
	std::cout << "Error" << std::endl;
	return (false);
}

std::string &RPN::ltrim(std::string &str)
{
	std::string::iterator it = str.begin();
	while (it != str.end() && std::isspace(*it))
	{
		it++;
	}
	str.erase(str.begin(), it);
	return (str);
}

std::string &RPN::rtrim(std::string &str)
{
	std::string::reverse_iterator rit = str.rbegin();
	while (rit != str.rend() && std::isspace(*rit))
	{
		++rit;
	}
	str.erase(rit.base(), str.end());
	return (str);
}

std::string &RPN::trim(std::string &str)
{
	return (ltrim(rtrim(str)));
}

std::string RPN::ensureOnlyOneConsecutiveWs(const std::string &input)
{
	bool inWhitespace;

	std::string result;
	inWhitespace = false;
	for (std::string::const_iterator it = input.begin(); it != input.end(); ++it)
	{
		if (std::isspace(*it))
		{
			if (!inWhitespace)
			{
				result += ' ';
				inWhitespace = true;
			}
		}
		else
		{
			result += *it;
			inWhitespace = false;
		}
	}
	return (result);
}