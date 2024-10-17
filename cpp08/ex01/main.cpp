/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:01:18 by smatthes          #+#    #+#             */
/*   Updated: 2024/10/17 10:10:45 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "external.hpp"

void	test_canonical_functions(void);
void	test_add_number(void);
void	test_add_numbers(void);
void	test_shortest_longest_span(void);
void	test_really_big_span(void);
void	tests_from_subject(void);

int	main(void)
{
	tests_from_subject();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "********test_canonical_functions*******";
	std::cout << std::endl;
	std::cout << std::endl;
	test_canonical_functions();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "********test_add_number*******";
	std::cout << std::endl;
	std::cout << std::endl;
	test_add_number();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "********test_add_numbers*******";
	std::cout << std::endl;
	std::cout << std::endl;
	test_add_numbers();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "********test_shortest_longest_span*******";
	std::cout << std::endl;
	std::cout << std::endl;
	test_shortest_longest_span();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "********test_really_big_span*******";
	std::cout << std::endl;
	std::cout << std::endl;
	test_really_big_span();
	return (0);
}

#define MAX_NUM 1000000

void	test_really_big_span(void)
{
	Span test_span(MAX_NUM);
	Span test_span_2(MAX_NUM);
	std::vector<int> vec(MAX_NUM);
	std::fill_n(vec.begin(), vec.size(), 42);
	for (int i = 0; i < MAX_NUM; i++)
	{
		test_span.addNumber(i);
	}
	test_span_2.addNumbers(vec.begin(), vec.end());
	std::cout << test_span.shortestSpan() << std::endl;
	std::cout << test_span.longestSpan() << std::endl;
	std::cout << test_span_2.shortestSpan() << std::endl;
	std::cout << test_span_2.longestSpan() << std::endl;
}

void	test_shortest_longest_span(void)
{
	Span span_test(5);
	Span span_empty(5);
	Span span_one(5);
	span_one.addNumber(2);
	span_test.addNumber(-2);
	span_test.addNumber(5);
	span_test.addNumber(14);
	span_test.addNumber(24);
	span_test.addNumber(-209);
	std::cout << std::endl << "Shortest Span:";
	std::cout << span_test.shortestSpan();
	std::cout << std::endl;
	std::cout << std::endl << "Longest Span:";
	std::cout << span_test.longestSpan();
	std::cout << std::endl;
	try
	{
		span_empty.shortestSpan();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: ";
		std::cerr << e.what() << '\n';
	}
	try
	{
		span_one.shortestSpan();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: ";
		std::cerr << e.what() << '\n';
	}
	try
	{
		span_empty.longestSpan();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: ";
		std::cerr << e.what() << '\n';
	}
	try
	{
		span_one.longestSpan();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: ";
		std::cerr << e.what() << '\n';
	}
}

void	test_add_numbers(void)
{
	Span span_vec(5);
	Span span_list(5);
	Span span_deque(5);
	Span span_contains_already_num(7);
	Span span_too_small(3);
	span_contains_already_num.addNumber(42);
	span_contains_already_num.addNumber(42);
	std::vector<int> vec(5);
	std::fill_n(vec.begin(), vec.size(), 21);
	std::list<int> list(5); // List of size 5
	std::fill_n(list.begin(), list.size(), 42);
	std::deque<int> deque(5); // Deque of size 5
	std::fill_n(deque.begin(), deque.size(), 84);
	span_contains_already_num.addNumbers(vec.begin(), vec.end());
	span_vec.addNumbers(vec.begin(), vec.end());
	span_list.addNumbers(list.begin(), list.end());
	span_deque.addNumbers(deque.begin(), deque.end());
	span_contains_already_num.print();
	span_vec.print();
	span_list.print();
	span_deque.print();
	try
	{
		span_too_small.addNumbers(vec.begin(), vec.end());
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: ";
		std::cerr << e.what() << '\n';
	}
	span_too_small.print();
}

void	test_add_number(void)
{
	Span span_test(3);
	try
	{
		span_test.addNumber(1);
		span_test.addNumber(2);
		span_test.addNumber(3);
		span_test.addNumber(4);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: ";
		std::cerr << e.what() << '\n';
		span_test.print();
	}
}

void	test_canonical_functions(void)
{
	Span span_blueprint(3);
	span_blueprint.addNumber(1);
	span_blueprint.addNumber(2);
	span_blueprint.addNumber(3);
	std::cout << "Blueprint span" << std::endl;
	span_blueprint.print();
	std::cout << std::endl;
	Span span_copy_constructor(span_blueprint);
	std::cout << "Copy constructed span" << std::endl;
	span_copy_constructor.print();
	std::cout << std::endl;
	Span span_copy_assignment(1);
	std::cout << "Copy assigned span before assignemnt" << std::endl;
	span_copy_assignment.print();
	std::cout << std::endl;
	span_copy_assignment = span_blueprint;
	std::cout << "Copy assigned span after assignemnt" << std::endl;
	span_copy_assignment.print();
	std::cout << std::endl;
}

void	tests_from_subject(void)
{
	Span	sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}
