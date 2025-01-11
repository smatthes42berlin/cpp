/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeque.hpp                                :+:      :+:    :+:   */
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

class PmergeMeDeque
{
  public:
	PmergeMeDeque();
	PmergeMeDeque(const PmergeMeDeque &other);
	PmergeMeDeque &operator=(const PmergeMeDeque &other);
	virtual ~PmergeMeDeque(void);

	void sort(int argc,
				char **argv,
				bool printDebug);
	void printDeque(std::deque<int> deque);

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

	std::deque<int> mainChain;
	std::deque<int> inputSequenceOrg;
	clock_t timeNeeded;

  private:
	clock_t timeBefore;
	clock_t timeAfter;
	std::deque<int_pair> sortedPairs;
	std::deque<int> inputSequence;
	std::deque<int> pend;
	int argc;
	char **argv;
	int numComparisons;
	bool odd;
	int oddRemainingB;

	void readInputSequence();
	int stringToInt(char *curToken);
	void createSortedPairs();
	void mergePairs(std::deque<int_pair> &deque, int left, int mid, int right);
	void mergeSortPairs(std::deque<int_pair> &deque, int left, int right);
	void createMainChainNPend();
	void insertPendIntoMainChain();

	unsigned int jacobsthalNum(unsigned int num);

	void printPairs(std::deque<int_pair> deque);
	void printRemainder();
	void printNumComparisons();
};

bool	countComparatorBinarySearch(int a, int b);
