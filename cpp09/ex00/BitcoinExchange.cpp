/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:52:06 by smatthes          #+#    #+#             */
/*   Updated: 2024/10/17 09:57:30 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "external.hpp"

BitcoinExchange::BitcoinExchange(void)
	: databasePath("./data.csv"),
		curDataBaseLine(0),
		curInputFileLine(0),
		curDataBaseDate(""),
		curDataBaseValue(0.0),
		inputFilePath("input.txt"),
		curInputFileDate(""),
		curInputFileValue(0.0)
{
	return ;
}

BitcoinExchange::BitcoinExchange(std::string curInputFilePath)
	: databasePath("./data.csv"),
		curDataBaseLine(0),
		curInputFileLine(0),
		curDataBaseDate(""),
		curDataBaseValue(0.0),
		inputFilePath(curInputFilePath),
		curInputFileDate(""),
		curInputFileValue(0.0)
{
	return ;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	this->database = other.database;
	this->databasePath = other.databasePath;
	this->curDataBaseLine = other.curDataBaseLine;
	this->curInputFileLine = other.curInputFileLine;
	this->curDataBaseDate = other.curDataBaseDate;
	this->curDataBaseValue = other.curDataBaseValue;
	this->inputFilePath = other.inputFilePath;
	this->curInputFileDate = other.curInputFileDate;
	this->curInputFileValue = other.curInputFileValue;
	return ;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		this->database = other.database;
		this->databasePath = other.databasePath;
		this->curDataBaseLine = other.curDataBaseLine;
		this->curInputFileLine = other.curInputFileLine;
		this->curDataBaseDate = other.curDataBaseDate;
		this->curDataBaseValue = other.curDataBaseValue;
		this->inputFilePath = other.inputFilePath;
		this->curInputFileDate = other.curInputFileDate;
		this->curInputFileValue = other.curInputFileValue;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
	return ;
}

void BitcoinExchange::run()
{
	this->readDatabase();
	this->readInputFile();
	// this->printDatabase();
	return ;
}

void BitcoinExchange::readInputFile(void)
{
	if (!this->check_file_access(this->databasePath))
		throw ErrorReadingInputFile();
	std::ifstream ifs(this->inputFilePath.c_str());
	if (!ifs.is_open())
		throw ErrorReadingInputFile();
	std::string line;
	while (std::getline(ifs, line))
	{
		this->curInputFileLine++;
		if (this->curInputFileLine == 1)
		{
			if (line != "date | value")
				this->inputFileBadInput(line);
		}
		else
		{
			if (this->checkLineInputFile(line))
				this->calcNPrintResult();
		}
	}
	if (!ifs.eof() && (ifs.fail() || ifs.bad()))
		throw ErrorReadingInputFile();
	ifs.close();
	return ;
}

void BitcoinExchange::calcNPrintResult(void)
{
	float	exchangeRate;

	exchangeRate = this->findClosestExchangeRate();
	std::cout << this->curInputFileDate;
	std::cout << " => ";
	std::cout << this->curInputFileValue;
	std::cout << " = ";
	std::cout << exchangeRate * this->curInputFileValue;
	std::cout << std::endl;
}

float BitcoinExchange::findClosestExchangeRate()
{
	// Find the iterator pointing to the first element not less than the given date
	std::map<std::string,
		float>::const_iterator it = this->database.lower_bound(this->curInputFileDate);
	if (it != this->database.end() && it->first == this->curInputFileDate)
	{
		return (it->second);
	}
	else if (it != this->database.begin())
	{
		--it;
		return (it->second);
	}
	else
	{
		std::cout << "CASE SHOULD NEVER HAPPEN: No closest exchange rate found!" << std::endl;
		return 0;
	}
}

void BitcoinExchange::readDatabase(void)
{
	if (!this->check_file_access(this->databasePath))
		throw ErrorReadingDatabase();
	std::ifstream ifs(this->databasePath.c_str());
	if (!ifs.is_open())
		throw ErrorReadingDatabase();
	std::string line;
	while (std::getline(ifs, line))
	{
		this->curDataBaseLine++;
		if (this->curDataBaseLine == 1)
		{
			if (line != "date,exchange_rate")
				this->printInvalidLineFormat("Wrong Header Line!");
		}
		else
		{
			if (this->checkLineDatabase(line))
				this->addLineToMap();
		}
	}
	if (!ifs.eof() && (ifs.fail() || ifs.bad()))
		throw ErrorReadingDatabase();
	ifs.close();
	if (this->database.size() == 0)
		throw ErrorReadingDatabase();
	return ;
}

void BitcoinExchange::addLineToMap()
{
	this->database[this->curDataBaseDate] = this->curDataBaseValue;
}

bool BitcoinExchange::checkLineInputFile(std::string line)
{
	size_t	verticalBarPos;
	float	value;

	std::string date;
	std::string valueStr;
	this->curDataBaseDate = "";
	this->curDataBaseValue = 0.0;
	verticalBarPos = line.find('|');
	if (verticalBarPos == std::string::npos)
	{
		this->inputFileBadInput(line);
		return (false);
	}
	if (line[verticalBarPos - 1] != ' ' || line[verticalBarPos + 1] != ' ')
	{
		this->inputFileBadInput(line);
		return (false);
	}
	date = line.substr(0, verticalBarPos - 1);
	if (!this->checkDateValidity(date))
	{
		this->inputFileBadInput(line);
		return (false);
	}
	valueStr = line.substr(verticalBarPos + 2);
	std::stringstream ss(valueStr);
	ss >> value;
	if (ss.fail() || !ss.eof())
	{
		this->inputFileBadInput(line);
		return (false);
	}
	if (value < 0)
	{
		this->inputFileNotAPositiveNumber();
		return (false);
	}
	if (value > 1000)
	{
		this->inputFileTooLargeNumber();
		return (false);
	}
	if (this->database.begin()->first > date)
	{
		this->inputFileBadInput(line);
		return (false);
	}
	this->curInputFileDate = date;
	this->curInputFileValue = value;
	return (true);
}

bool BitcoinExchange::checkLineDatabase(std::string line)
{
	size_t	commaPos;
	float	value;

	std::string date;
	std::string valueStr;
	this->curDataBaseDate = "";
	this->curDataBaseValue = 0.0;
	commaPos = line.find(',');
	if (commaPos == std::string::npos)
	{
		this->printInvalidLineFormat("No comma found!");
		return (false);
	}
	date = line.substr(0, commaPos);
	if (!this->checkDateValidity(date))
	{
		this->printInvalidLineFormat("Invalid Date Format!");
		return (false);
	}
	valueStr = line.substr(commaPos + 1);
	std::stringstream ss(valueStr);
	ss >> value;
	if (ss.fail() || !ss.eof())
	{
		this->printInvalidLineFormat("Invalid Float Format!");
		return (false);
	}
	if (this->database.find(date) != this->database.end())
	{
		this->printInvalidLineFormat("Duplicate Date detected!");
		return (false);
	}
	this->curDataBaseDate = date;
	this->curDataBaseValue = value;
	return (true);
}

bool BitcoinExchange::checkDateValidity(std::string dateStr)
{
	int					year;
	int					month;
	int					day;
	bool				isLeapYear;
	int					maxDays;

	// daysInMonth[];
	if (dateStr.size() != 10 || dateStr[4] != '-' || dateStr[7] != '-')
	{
		// this->printInvalidLineFormat("Invalid Date Format!");
		return (false);
	}
	for (size_t i = 0; i < dateStr.size(); ++i)
	{
		if ((i == 4 || i == 7) && dateStr[i] == '-')
		{
			continue ;
		}
		if (!std::isdigit(dateStr[i]))
		{
			// this->printInvalidLineFormat("Invalid Date Format!");
			return (false);
		}
	}
	year = std::atoi(dateStr.substr(0, 4).c_str());
	month = std::atoi(dateStr.substr(5, 2).c_str());
	day = std::atoi(dateStr.substr(8, 2).c_str());
	// if (year < 2009 || year > 2025)
	// {
	// 	// this->printInvalidLineFormat("Year out of range (2009-2025)!");
	// 	return (false);
	// }
	if (month < 1 || month > 12)
	{
		// this->printInvalidLineFormat("Month out of range (1-12)!");
		return (false);
	}
	if (day < 1 || day > 31)
	{
		// this->printInvalidLineFormat("Day out of range (1-31)!");
		return (false);
	}
	static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
	maxDays = daysInMonth[month - 1];
	if (month == 2 && isLeapYear)
	{
		maxDays = 29;
	}
	if (day > maxDays)
	{
		// this->printInvalidLineFormat("Invalid day for the given month!");
		return (false);
	}
	return (true);
}

bool BitcoinExchange::check_file_access(std::string filePath)
{
	struct stat	pathStat;

	if (access(filePath.c_str(), R_OK) != 0)
		return (false);
	if (stat(filePath.c_str(), &pathStat) != 0)
		return (false);
	if (S_ISDIR(pathStat.st_mode))
		return (false);
	return (true);
}

const char *BitcoinExchange::ErrorReadingDatabase::what() const throw()
{
	return ("An error occured while trying to read the database!\n");
}

const char *BitcoinExchange::ErrorReadingInputFile::what() const throw()
{
	return ("An error occured while trying to read the input File!\n");
}

void BitcoinExchange::printInvalidLineFormat(std::string const msg)
{
	std::cout << "Parsing Database: Invalid Format in Line " << this->curDataBaseLine;
	std::cout << ": " << msg << std::endl;
}

void BitcoinExchange::inputFileNotAPositiveNumber()
{
	std::cout << "Error: not a positive number." << std::endl;
}

void BitcoinExchange::inputFileBadInput(std::string line)
{
	std::cout << "Error: bad input => " << line << std::endl;
}

void BitcoinExchange::inputFileTooLargeNumber()
{
	std::cout << "Error: too large a number." << std::endl;
}

void BitcoinExchange::printDatabase(void)
{
	std::cout << "DATABASE:" << std::endl;
	for (std::map<std::string,
					float>::iterator it = this->database.begin();
			it != this->database.end();
			++it)
	{
		std::cout << it->first << ": " << it->second << std::endl;
	}
}
