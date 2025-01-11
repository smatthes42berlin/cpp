/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVector.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:52:06 by smatthes          #+#    #+#             */
/*   Updated: 2024/10/17 09:57:30 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMeVector.hpp"
#include "external.hpp"

int		numComparisonsBinarySearch = 0;

bool	countComparatorBinarySearch(int a, int b)
{
	numComparisonsBinarySearch++;
	return (a < b);
}

PmergeMeVector::PmergeMeVector(void)
	: argc(1), argv(NULL), numComparisons(0), odd(false)
{
	return ;
}

PmergeMeVector::PmergeMeVector(const PmergeMeVector &other)
{
	this->argc = other.argc;
	this->argv = other.argv;
	this->numComparisons = other.numComparisons;
	this->odd = other.odd;
	this->oddRemainingB = other.oddRemainingB;
	this->inputSequence = other.inputSequence;
	this->sortedPairs = other.sortedPairs;
	this->mainChain = other.mainChain;
	this->pend = other.pend;
	this->timeNeeded = other.timeNeeded;
	this->timeBefore = other.timeBefore;
	this->timeNeeded = other.timeNeeded;
	return ;
}

PmergeMeVector &PmergeMeVector::operator=(const PmergeMeVector &other)
{
	if (this != &other)
	{
		this->argc = other.argc;
		this->argv = other.argv;
		this->numComparisons = other.numComparisons;
		this->odd = other.odd;
		this->oddRemainingB = other.oddRemainingB;
		this->inputSequence = other.inputSequence;
		this->sortedPairs = other.sortedPairs;
		this->mainChain = other.mainChain;
		this->pend = other.pend;
		this->timeNeeded = other.timeNeeded;
		this->timeBefore = other.timeBefore;
		this->timeNeeded = other.timeNeeded;
	}
	return (*this);
}

PmergeMeVector::~PmergeMeVector(void)
{
	return ;
}

void PmergeMeVector::sort(int argc,
							char **argv,
							bool printDebug)
{
	numComparisonsBinarySearch = 0;
	this->argc = argc;
	this->argv = argv;
	if (printDebug)
	{
		std::cout << "sorting using Vector" << std::endl;
	}
	this->timeBefore = clock();
	this->readInputSequence();
	this->inputSequenceOrg = this->inputSequence;
	if (printDebug)
	{
		std::cout << "Input Numbers to vector sort: ";
		this->printVector(this->inputSequence);
	}
	if (this->inputSequence.size() % 2 == 1)
	{
		this->odd = true;
		this->oddRemainingB = this->inputSequence.back();
		this->inputSequence.pop_back();
	}
	this->createSortedPairs();
	if (printDebug)
	{
		std::cout << "Created Pairs each sorted: ";
		this->printPairs(this->sortedPairs);
		this->printRemainder();
		this->printNumComparisons();
	}
	this->mergeSortPairs(this->sortedPairs, 0, this->sortedPairs.size() - 1);
	if (printDebug)
	{
		std::cout << "Sorted all Pairs: ";
		this->printPairs(this->sortedPairs);
		this->printNumComparisons();
	}
	this->createMainChainNPend();
	if (printDebug)
	{
		std::cout << "Created Main Chain: ";
		this->printVector(this->mainChain);
		std::cout << "Created Main Pend: ";
		this->printVector(this->pend);
		this->printNumComparisons();
	}
	this->insertPendIntoMainChain();
	if (this->odd)
	{
		std::vector<int>::iterator it =
			std::lower_bound(this->mainChain.begin(), this->mainChain.end(),
					this->oddRemainingB);
		if (it == this->mainChain.end())
			this->mainChain.push_back(this->oddRemainingB);
		else
			this->mainChain.insert(it, this->oddRemainingB);
	}
	this->numComparisons += numComparisonsBinarySearch;
	if (printDebug)
	{
		std::cout << "Sorted Main Chain: ";
		this->printVector(this->mainChain);
		std::cout << "Remaining Pend: ";
		this->printVector(this->pend);
		this->printNumComparisons();
	}
	numComparisonsBinarySearch = 0;
	this->timeAfter = clock();
	this->timeNeeded = this->timeAfter - this->timeBefore;
}

void PmergeMeVector::insertPendIntoMainChain()
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
									this->mainChain.begin() + (1 << (i - 1))
										- 1,
									this->pend.at(j),
									countComparatorBinarySearch);
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
}

void PmergeMeVector::createMainChainNPend()
{
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

void PmergeMeVector::mergeSortPairs(std::vector<int_pair> &vec, int left,
		int right)
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

void PmergeMeVector::mergePairs(std::vector<int_pair> &vec, int left, int mid,
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

void PmergeMeVector::createSortedPairs()
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
void PmergeMeVector::readInputSequence()
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

int PmergeMeVector::stringToInt(char *curToken)
{
	int	value;

	std::string curString(curToken);
	std::stringstream ss(curString);
	ss >> value;
	if (ss.fail() || !ss.eof())
		throw ParsingException();
	return (value);
}

char const *PmergeMeVector::ParsingException::what(void) const throw()
{
	return ("Error: parsing error!");
}
char const *PmergeMeVector::DuplicateException::what(void) const throw()
{
	return ("Error: duplicate element!");
}
char const *PmergeMeVector::IntNegativeException::what(void) const throw()
{
	return ("Error: negative element!");
}

void PmergeMeVector::printVector(std::vector<int> vec)
{
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << *it;
		std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMeVector::printPairs(std::vector<int_pair> vec)
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

void PmergeMeVector::printRemainder()
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

void PmergeMeVector::printNumComparisons()
{
	std::cout << "Num comparisons " << this->numComparisons << std::endl;
}

unsigned int PmergeMeVector::jacobsthalNum(unsigned int num)
{
	if (num == 0)
		return (0);
	if (num == 1)
		return (1);
	return (jacobsthalNum(num - 1) + 2 * jacobsthalNum(num - 2));
}
