/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:04:58 by smatthes          #+#    #+#             */
/*   Updated: 2024/10/06 12:15:37 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "external.hpp"

class NotFoundException : public std::exception
{
	const char *what() const throw()
	{
		return ("Int value not found in container");
	}
};

template <typename T>
typename T::iterator easyfind(T &container, const int i)
{
	typename T::iterator it = std::find(container.begin(), container.end(), i);

	if (it == container.end())
	{
		throw NotFoundException();
	}
	return (it);
}