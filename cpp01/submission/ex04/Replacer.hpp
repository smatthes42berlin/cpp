/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:16:45 by smatthes          #+#    #+#             */
/*   Updated: 2024/07/21 16:43:38 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "external.hpp"

#pragma once

class Replacer
{
  public:
	Replacer();
	~Replacer();

	int replace(int argc, char *argv[]);

  private:
	int _argc;
	std::string _inFileName;
	std::string _searchString;
	std::string _replaceString;
	std::ofstream _outFileStream;
	std::ifstream _inFileStream;

	bool argNumChecker() const;
	bool openOutFile();
	bool openInFile();
	bool replace();
	std::string replaceWordInLine(std::string line) const;
};
