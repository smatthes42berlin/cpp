/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:52:06 by smatthes          #+#    #+#             */
/*   Updated: 2024/10/05 13:01:56 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "external.hpp"

Base::~Base(void)
{
	std::cout << "<destructor> Base" << std::endl;
	return ;
}


