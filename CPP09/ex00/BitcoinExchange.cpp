/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:38:06 by yabejani          #+#    #+#             */
/*   Updated: 2025/04/24 19:12:40 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// BitcoinExchange.cpp
#include "BitcoinExchange.hpp"

#include <cstdlib>
#include <sstream>

BitcoinExchange::BitcoinExchange(){
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other){
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other){
	if (this != &other) {
		_rates = other._rates;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange(){
}

void BitcoinExchange::loadDB(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
    {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	getline(file, line); // skip header
	while (getline(file, line))
    {
		size_t sep = line.find(',');
		if (sep == std::string::npos) continue;
		std::string date = line.substr(0, sep);
		float rate = std::atof(line.substr(sep + 1).c_str());
		_rates[date] = rate;
	}
	file.close();
}

static bool isValidDateFormat(const std::string& date)
{
	int dashCount = 0;
	for (std::string::const_iterator it = date.begin(); it != date.end(); ++it)
    {
		if (*it == '-') dashCount++;
	}
	return dashCount == 2;
}

static bool isValidDate(const std::string& date)
{
	if (!isValidDateFormat(date))
        return false;

	std::istringstream ss(date);
	std::string yearStr, monthStr, dayStr;
	if (!getline(ss, yearStr, '-'))
        return false;
	if (!getline(ss, monthStr, '-'))
        return false;
	if (!getline(ss, dayStr))
        return false;

	//int year = std::atoi(yearStr.c_str());
	int month = std::atoi(monthStr.c_str());
	int day = std::atoi(dayStr.c_str());

	if (month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	return true;
}

void BitcoinExchange::evaluateInput(const std::string& filename) const
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
    {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	getline(file, line); // skip header
	while (getline(file, line))
    {
		size_t sep = line.find(" | ");
		if (sep == std::string::npos)
        {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = line.substr(0, sep);
		std::string valueStr = line.substr(sep + 3);
		float value = std::atof(valueStr.c_str());

		if (!isValidDate(date))
        {
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}
		if (value < 0)
        {
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000)
        {
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		std::map<std::string, float>::const_iterator it = _rates.lower_bound(date);
		if (it == _rates.end() || it->first != date)
        {
			if (it == _rates.begin())
            {
				std::cerr << "Error: bad input => " << date << std::endl;
				continue;
			}
			--it;
		}
		std::cout << date << " => " << value << " = " << value * it->second << std::endl;
	}
	file.close();
}
