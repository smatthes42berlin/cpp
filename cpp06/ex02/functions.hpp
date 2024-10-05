/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:12:19 by smatthes          #+#    #+#             */
/*   Updated: 2024/10/05 13:36:47 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include "external.hpp"

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);
