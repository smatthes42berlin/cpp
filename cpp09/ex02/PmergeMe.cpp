/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:52:06 by smatthes          #+#    #+#             */
/*   Updated: 2024/10/17 09:57:30 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "external.hpp"

PmergeMe::PmergeMe(void)
	: argc(1), argv(NULL)
{
	return ;
}

PmergeMe::PmergeMe(int curArgc, char **curArgv)
	: argc(curArgc), argv(curArgv)
{
	return ;
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	this->argc = other.argc;
	this->argv = other.argv;
	return ;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->argc = other.argc;
		this->argv = other.argv;
	}
	return (*this);
}

PmergeMe::~PmergeMe(void)
{
	return ;
}

void PmergeMe::sort(void)
{
	try
	{
		vectorSorter.sort(this->argc, this->argv, PRINT_DEBUG);
		dequeSorter.sort(this->argc, this->argv, PRINT_DEBUG);
		std::cout << "Before:\t";
		vectorSorter.printVector(vectorSorter.inputSequenceOrg);
		std::cout << "After:\t";
		vectorSorter.printVector(vectorSorter.mainChain);
		std::cout << "Time to process a range of " << vectorSorter.inputSequenceOrg.size();
		std::cout << " elements with std::vector :";
		elapsedTimeInMicroseconds = static_cast<double>(vectorSorter.timeNeeded)
			/ CLOCKS_PER_SEC * 1e6;
		std::cout << "\t" << elapsedTimeInMicroseconds << " us";
		std::cout << std::endl;
		std::cout << "Time to process a range of " << dequeSorter.inputSequenceOrg.size();
		std::cout << " elements with std::deque  :";
		elapsedTimeInMicroseconds = static_cast<double>(dequeSorter.timeNeeded)
			/ CLOCKS_PER_SEC * 1e6;
		std::cout << "\t" << elapsedTimeInMicroseconds << " us";
		std::cout << std::endl;
	}
	catch (std::exception &err)
	{
		std::cerr << err.what() << std::endl;
	}
}
