/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:51:56 by smatthes          #+#    #+#             */
/*   Updated: 2025/01/05 11:28:11 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "PmergeMeVector.hpp"
#include "PmergeMeDeque.hpp"
#include "external.hpp"

#define PRINT_DEBUG false

class PmergeMe
{
  public:
	PmergeMe();
	PmergeMe(int argc, char **argv);
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	virtual ~PmergeMe(void);

	void sort(void);

	class ParsingException : public std::exception
	{
		public:
		virtual char const *what() const throw();
	};
	class DuplicateException : public std::exception
	{
		public:
		virtual char const *what() const throw();
	};
	class IntNegativeException : public std::exception
	{
		public:
		virtual char const *what() const throw();
	};

  private:
  	int argc;
	char **argv;
	PmergeMeVector vectorSorter;
	PmergeMeDeque dequeSorter;
	double elapsedTimeInMicroseconds;
};
