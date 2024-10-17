/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:01:18 by smatthes          #+#    #+#             */
/*   Updated: 2024/10/17 16:14:16 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "external.hpp"

template <typename Container>
//
void	printContainer(const Container &container)
{
	typename Container::const_iterator it;
	for (it = container.begin(); it != container.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template <typename T> void printAndEmptyStack(std::stack<T> stack)
{
	// Loop while the stack is not empty
	while (!stack.empty())
	{
		std::cout << stack.top() << " "; // Access the top element
		stack.pop();                     // Remove the top element
	}
	std::cout << std::endl;
}

void	test_from_subject_mutant_stack(void);
void	test_from_subject_list(void);

int	main(void)
{
    std::cout << "**********output as mutantstack*********";
    std::cout << std::endl << std::endl;
	test_from_subject_mutant_stack();
    std::cout << std::endl << std::endl;
    std::cout << "**********output as list*********";
    std::cout << std::endl << std::endl;
	test_from_subject_list();
	// std::stack<int, std::deque<int> > test_stack_deque;
	// MutantStack<int, std::deque<int> > test_stack_mutant_deque;
	// MutantStack<int, std::vector<int> > test_stack_mutant_vector;
	// // push(): Adds an element to the top of the stack.
	// // pop(): Removes the top element from the stack.
	// // top(): Returns a reference to the top element of the stack.
	// // empty(): Returns true if the stack is empty.
	// // size(): Returns the number of elements in the stack.
	// test_stack_deque.push(1);
	// test_stack_deque.push(2);
	// test_stack_deque.push(3);
	// test_stack_mutant_deque.push(1);
	// test_stack_mutant_deque.push(2);
	// test_stack_mutant_deque.push(3);
	// test_stack_mutant_vector.push(1);
	// test_stack_mutant_vector.push(2);
	// test_stack_mutant_vector.push(3);
	// printContainer(test_stack_mutant_deque);
	// std::cout << std::endl;
	// printContainer(test_stack_mutant_vector);
	// std::cout << std::endl;
	// printAndEmptyStack(test_stack_mutant_deque);
	return (0);
}

void	test_from_subject_mutant_stack(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void	test_from_subject_list(void)
{
	std::list<int> test_list;
	test_list.push_back(5);
	test_list.push_back(17);
	std::cout << test_list.back() << std::endl;
	test_list.pop_back();
	std::cout << test_list.size() << std::endl;
	test_list.push_back(3);
	test_list.push_back(5);
	test_list.push_back(737);
	//[...]
	test_list.push_back(0);
	std::list<int>::iterator it = test_list.begin();
	std::list<int>::iterator ite = test_list.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> s(test_list);
}