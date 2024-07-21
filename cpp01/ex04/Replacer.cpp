/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:16:45 by smatthes          #+#    #+#             */
/*   Updated: 2024/07/21 16:54:04 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

Replacer::Replacer()
{
	return ;
}

Replacer::~Replacer()
{
	return ;
}

std::string Replacer::replaceWordInLine(std::string line) const
{
	std::string replaced = line;
	std::string leftSide;
	std::string rightSide;
	if (this->_searchString.empty())
		return (replaced);
	int searchLength = this->_searchString.length();
	std::size_t found = replaced.find(this->_searchString);
	while (found != std::string::npos)
	{
		leftSide = replaced.substr(0, found);
		rightSide = replaced.substr(found + searchLength);
		replaced = leftSide + this->_replaceString + rightSide;
		found = replaced.find(this->_searchString);
	}
	return (replaced);
}

int Replacer::replace(int argc, char *argv[])
{
	this->_argc = argc;
	if (!this->argNumChecker())
		return (1);
	this->_inFileName = argv[1];
	this->_searchString = argv[2];
	this->_replaceString = argv[3];
	if (!this->openInFile())
		return (2);
	if (!this->openOutFile())
		return (3);
	if (!this->replace())
		return (4);
	return (0);
}

bool Replacer::replace(void)
{
	std::string line;
	while (getline(this->_inFileStream, line))
	{
		this->_outFileStream << this->replaceWordInLine(line);
		this->_outFileStream << std::endl;
	}
	this->_outFileStream.close();
	this->_inFileStream.close();
	return (true);
}

bool Replacer::openOutFile()
{
	std::string outFileName = this->_inFileName + ".replace";
	this->_outFileStream.open(outFileName.c_str());
	if (!this->_outFileStream.is_open())
	{
		std::cerr << "File '";
		std::cerr << outFileName;
		std::cerr << "' couldn't be opened!";
		std::cerr << std::endl;
		this->_inFileStream.close();
		return (false);
	}
	return (true);
}

bool Replacer::openInFile()
{
	this->_inFileStream.open(this->_inFileName.c_str());
	if (!this->_inFileStream.is_open())
	{
		std::cerr << "File '";
		std::cerr << this->_inFileName;
		std::cerr << "' couldn't be opened!";
		std::cerr << std::endl;
		return (false);
	}
	return (true);
}

bool Replacer::argNumChecker() const
{
	if (this->_argc != 4)
	{
		std::cerr << "Wrong number of arguments!";
		std::cerr << std::endl;
		std::cerr << "Provide: filename, searchStr, replaceStr";
		std::cerr << std::endl;
		return (false);
	}
	return (true);
}