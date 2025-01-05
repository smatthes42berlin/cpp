/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:51:56 by smatthes          #+#    #+#             */
/*   Updated: 2025/01/05 11:28:11 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "external.hpp"

class RPN
{
  public:
	RPN();
	RPN(std::string curRpnExpression);
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	virtual ~RPN(void);

	void calc();

  private:
	std::string rpnExpression;
	std::stack<float> stack;

	bool printError();
	bool processToken(std::string curToken);
	bool processOperator(std::string curToken);
	bool processOperand(std::string curToken);
	std::string &ltrim(std::string &str);
	std::string &rtrim(std::string &str);
	std::string &trim(std::string &str);
	std::string ensureOnlyOneConsecutiveWs(const std::string &input);
};
