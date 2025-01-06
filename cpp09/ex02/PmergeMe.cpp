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

int		numComparisonsBinarySearch = 0;

bool	countComparatorBinarySearch(int a, int b)
{
	numComparisonsBinarySearch++;
	return (a < b);
}

PmergeMe::PmergeMe(void)
	: argc(1), argv(NULL), numComparisons(0), odd(false)
{
	return ;
}

PmergeMe::PmergeMe(int curArgc, char **curArgv)
	: argc(curArgc), argv(curArgv), numComparisons(0), odd(false)
{
	return ;
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	this->argc = other.argc;
	this->argv = other.argv;
	this->numComparisons = other.numComparisons;
	this->odd = other.odd;
	return ;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->argc = other.argc;
		this->argv = other.argv;
		this->odd = other.odd;
	}
	return (*this);
}

PmergeMe::~PmergeMe(void)
{
	return ;
}

void PmergeMe::sort(void)
{
	this->readInputSequence();
	this->printVector(this->inputSequence);
	if (this->inputSequence.size() % 2 == 1)
	{
		this->odd = true;
		this->oddRemainingB = this->inputSequence.back();
		this->inputSequence.pop_back();
	}
	this->createSortedPairs();
	this->printPairs(this->sortedPairs);
	this->printRemainder();
	this->printNumComparisons();
	this->mergeSortPairs(this->sortedPairs, 0, this->sortedPairs.size() - 1);
	this->printPairs(this->sortedPairs);
	this->printNumComparisons();
	this->createMainChainNPend();
	this->printVector(this->mainChain);
	this->printVector(this->pend);
	this->printNumComparisons();
	this->insertPendIntoMainChain();
	if (this->odd)
	{
		std::vector<int>::iterator it =
			std::lower_bound(this->mainChain.begin(), this->mainChain.end(), this->oddRemainingB);
		if (it == this->mainChain.end())
			this->mainChain.push_back(this->oddRemainingB);
		else
			this->mainChain.insert(it, this->oddRemainingB);
	}
	this->numComparisons += numComparisonsBinarySearch;
	this->printVector(this->mainChain);
	this->printVector(this->pend);
	this->printNumComparisons();
}

void PmergeMe::insertPendIntoMainChain()
{
	int	diff;

	for (int i = 3;; i++)
	{
		diff = this->jacobsthalNum(i) - this->jacobsthalNum(i - 1);
		if (diff > static_cast<int>(this->pend.size()))
			break ;
		for (int j = diff - 1; j >= 0; j--)
		{
			// here lies the optimisation for the binary search
			// 2 ^ (i - 1) - 1
			// (1 << (i - 1)) - 1
			std::vector<int>::iterator it =
				std::lower_bound(this->mainChain.begin(),
						this->mainChain.begin() + (1 << (i - 1)) - 1,
						this->pend.at(j), countComparatorBinarySearch);
			this->mainChain.insert(it, this->pend.at(j));
			this->pend.erase(this->pend.begin() + j);
		}
	}
	for (std::vector<int>::reverse_iterator it = this->pend.rbegin();
			it != this->pend.rend();
			it++)
	{
		std::vector<int>::iterator current =
			std::lower_bound(this->mainChain.begin(), this->mainChain.end(),
					*it, countComparatorBinarySearch);
		this->mainChain.insert(current, *it);
	}
	// start with 3
	// std::vector<int>::iterator it = std::lower_bound(this->mainChain.begin(),
	// 		vec.end(), value_to_find, this->countComparatorBinarySearch);
	// always start at beginning
	// got to
}

void PmergeMe::createMainChainNPend()
{
	// this->mainChain.push_back(this->sortedPairs.begin()->first);
	for (std::vector<int_pair>::iterator it = this->sortedPairs.begin(); it != this->sortedPairs.end(); it++)
	{
		if (it != this->sortedPairs.begin())
		{
			this->mainChain.push_back(it->second);
			this->pend.push_back(it->first);
		}
		else
		{
			this->mainChain.push_back(it->first);
			this->mainChain.push_back(it->second);
		}
	}
}

void PmergeMe::mergeSortPairs(std::vector<int_pair> &vec, int left, int right)
{
	int	mid;

	if (left < right)
	{
		mid = left + (right - left) / 2;
		this->mergeSortPairs(vec, left, mid);
		this->mergeSortPairs(vec, mid + 1, right);
		this->mergePairs(vec, left, mid, right);
	}
}

void PmergeMe::mergePairs(std::vector<int_pair> &vec, int left, int mid,
		int right)
{
	int	n1;
	int	n2;
	int	i;
	int	j;
	int	k;

	n1 = mid - left + 1;
	n2 = right - mid;
	std::vector<int_pair> leftVec(n1);
	std::vector<int_pair> rightVec(n2);
	for (int i = 0; i < n1; ++i)
	{
		leftVec[i] = vec[left + i];
	}
	for (int i = 0; i < n2; ++i)
	{
		rightVec[i] = vec[mid + 1 + i];
	}
	i = 0, j = 0, k = left;
	while (i < n1 && j < n2)
	{
		if (leftVec[i].second <= rightVec[j].second)
		{
			vec[k] = leftVec[i];
			++i;
		}
		else
		{
			vec[k] = rightVec[j];
			++j;
		}
		this->numComparisons++;
		++k;
	}
	while (i < n1)
	{
		vec[k] = leftVec[i];
		++i;
		++k;
	}
	while (j < n2)
	{
		vec[k] = rightVec[j];
		++j;
		++k;
	}
}

void PmergeMe::createSortedPairs()
{
	int_pair	new_pair;

	for (std::vector<int>::iterator it = this->inputSequence.begin(); it != this->inputSequence.end(); it = it
			+ 2)
	{
		this->numComparisons++;
		if (*it > *(it + 1))
		{
			new_pair.first = *(it + 1);
			new_pair.second = *it;
		}
		else
		{
			new_pair.first = *it;
			new_pair.second = *(it + 1);
		}
		this->sortedPairs.push_back(new_pair);
	}
}
void PmergeMe::readInputSequence()
{
	int	num;

	for (int i = 1; i < this->argc; i++)
	{
		num = stringToInt(this->argv[i]);
		if (num < 0)
			throw IntNegativeException();
		if (std::find(this->inputSequence.begin(),
						this->inputSequence.end(),
						num) != this->inputSequence.end())
			throw DuplicateException();
		this->inputSequence.push_back(num);
	}
}

int PmergeMe::stringToInt(char *curToken)
{
	int	value;

	std::string curString(curToken);
	std::stringstream ss(curString);
	ss >> value;
	if (ss.fail() || !ss.eof())
		throw ParsingException();
	return (value);
}

char const *PmergeMe::ParsingException::what(void) const throw()
{
	return ("Error: parsing error!");
}
char const *PmergeMe::DuplicateException::what(void) const throw()
{
	return ("Error: duplicate element!");
}
char const *PmergeMe::IntNegativeException::what(void) const throw()
{
	return ("Error: negative element!");
}

void PmergeMe::printVector(std::vector<int> vec)
{
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << *it;
		std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printPairs(std::vector<int_pair> vec)
{
	for (std::vector<int_pair>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << "(";
		std::cout << it->first;
		std::cout << ",";
		std::cout << it->second;
		std::cout << ")";
		std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printRemainder()
{
	if (this->odd)
	{
		std::cout << "odd,remainder is " << this->oddRemainingB << std::endl;
	}
	else
	{
		std::cout << "even, no remainder " << std::endl;
	}
}

void PmergeMe::printNumComparisons()
{
	std::cout << "Num comparisons " << this->numComparisons << std::endl;
}

unsigned int PmergeMe::jacobsthalNum(unsigned int num)
{
	if (num == 0)
		return (0);
	if (num == 1)
		return (1);
	return (jacobsthalNum(num - 1) + 2 * jacobsthalNum(num - 2));
}
