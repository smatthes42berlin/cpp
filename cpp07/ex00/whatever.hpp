/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:04:58 by smatthes          #+#    #+#             */
/*   Updated: 2024/10/05 16:28:45 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void	swap(T &a, T &b)
{
	T	temp;

	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T const &min(T const &a, T const &b)
{
	return (a < b ? a : b);
}

template <typename T>
T const &max(T const &a, T const &b)
{
	return (a > b ? a : b);
}