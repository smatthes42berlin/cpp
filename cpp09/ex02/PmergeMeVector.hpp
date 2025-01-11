/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVector.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:51:56 by smatthes          #+#    #+#             */
/*   Updated: 2025/01/05 11:28:11 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "external.hpp"

typedef std::pair<int, int> int_pair;

class PmergeMeVector
{
  public:
	PmergeMeVector();
	PmergeMeVector(const PmergeMeVector &other);
	PmergeMeVector &operator=(const PmergeMeVector &other);
	virtual ~PmergeMeVector(void);

	void sort(int argc,
				char **argv,
				bool printDebug);
	void printVector(std::vector<int> vec);

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

	std::vector<int> mainChain;
	std::vector<int> inputSequenceOrg;
	clock_t timeNeeded;

  private:
	clock_t timeBefore;
	clock_t timeAfter;
	std::vector<int_pair> sortedPairs;
	std::vector<int> inputSequence;
	std::vector<int> pend;
	int argc;
	char **argv;
	int numComparisons;
	bool odd;
	int oddRemainingB;

	void readInputSequence();
	int stringToInt(char *curToken);
	void createSortedPairs();
	void mergePairs(std::vector<int_pair> &vec, int left, int mid, int right);
	void mergeSortPairs(std::vector<int_pair> &vec, int left, int right);
	void createMainChainNPend();
	void insertPendIntoMainChain();

	unsigned int jacobsthalNum(unsigned int num);

	void printPairs(std::vector<int_pair> vec);
	void printRemainder();
	void printNumComparisons();
};

bool	countComparatorBinarySearch(int a, int b);
