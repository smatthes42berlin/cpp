/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SampleClass.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes  <smatthes@student.42berlin>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:33:01 by smatthes          #+#    #+#             */
/*   Updated: 2024/07/18 10:22:27 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

#include <string>


class Sample
{
  public:

	Sample(void);
	~Sample(void);

	void setFirstName(std::string first);

	std::string firstName;
};

#endif