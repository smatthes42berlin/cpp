/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:51:56 by smatthes          #+#    #+#             */
/*   Updated: 2025/01/05 11:28:11 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "external.hpp"

class BitcoinExchange
{
  public:
	BitcoinExchange();
	BitcoinExchange(std::string curInputFilePath);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	virtual ~BitcoinExchange(void);

	void run();

	class ErrorReadingDatabase : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};

	class ErrorReadingInputFile : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};

  private:
	std::map<std::string, float> database;
	std::string databasePath;
	int curDataBaseLine;
	int curInputFileLine;
	std::string curDataBaseDate;
	float curDataBaseValue;
	std::string inputFilePath;
	std::string curInputFileDate;
	float curInputFileValue;

	bool check_file_access(std::string filePath);
	void readDatabase();
	bool checkLineDatabase(std::string line);
	bool checkLineInputFile(std::string line);
	void printInvalidLineFormat(std::string const msg);
	void addLineToMap();
	void printDatabase(void);
	bool checkDateValidity(std::string dateStr);
	void readInputFile(void);
	void calcNPrintResult(void);
	void inputFileNotAPositiveNumber();
	void inputFileBadInput(std::string line);
	void inputFileTooLargeNumber();
	float findClosestExchangeRate();
};
