/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:01:18 by smatthes          #+#    #+#             */
/*   Updated: 2024/10/06 10:56:26 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "external.hpp"

void test_from_subject(void);


int main(int, char**)
{
    Array<int> arr_int(3);
    Array<int> const arr_int_const(5);
    Array<float> arr_float(3);
    Array<char> arr_char(3);
    Array<std::string> arr_string(3);
    std::cout << arr_int;
    std::cout << arr_float;
    std::cout << arr_char;
    std::cout << arr_string;
    arr_int[0] = 0;
    arr_int[1] = 1;
    arr_int[2] = 2;
    arr_float[0] = 0.1;
    arr_float[1] = 1.2;
    arr_float[2] = 2.3;
    arr_char[0] = 'a';
    arr_char[1] = 'b';
    arr_char[2] = 'c';
    arr_string[0] = "a1";
    arr_string[1] = "b2";
    arr_string[2] = "c3";
    std::cout << arr_int;
    std::cout << arr_float;
    std::cout << arr_char;
    std::cout << arr_string;
    std::cout << arr_int_const;
    test_from_subject();
    return (0);
}

#define MAX_VAL 750
void test_from_subject(void)
{
     Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    // SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
}