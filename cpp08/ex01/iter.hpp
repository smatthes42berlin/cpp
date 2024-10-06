/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:04:58 by smatthes          #+#    #+#             */
/*   Updated: 2024/10/05 17:19:22 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T, typename F>
void	iter(T *arr, int arr_length, F func)
{
	for (int i = 0; i < arr_length; i++)
	{
		func(arr[i]);
	}
}

template <typename T>
void	print(T elem)
{
	std::cout << elem << " ";
}

template <typename T>
void	increment(T &elem)
{
	elem++;
}




