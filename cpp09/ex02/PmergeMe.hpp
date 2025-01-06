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
#include "external.hpp"

typedef std::pair<int, int> int_pair;

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
	std::vector<int> inputSequence;
	std::vector<int_pair> sortedPairs;
	std::vector<int> mainChain;
	std::vector<int> pend;
	// std::deque<int> dequeInputSequence;
	// std::list<int> listInputSequence;
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
	void printVector(std::vector<int> vec);
	void printRemainder();
	void printNumComparisons();
};


bool countComparatorBinarySearch(int a, int b);
