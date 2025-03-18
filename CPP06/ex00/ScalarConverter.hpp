/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:05:25 by yabejani          #+#    #+#             */
/*   Updated: 2025/03/18 19:21:56 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include "colors.hpp"

class ScalarConverter
{
    private:
        ScalarConverter();
		ScalarConverter(ScalarConverter const &src);
		ScalarConverter	&operator=(const ScalarConverter &rhs);

		~ScalarConverter();

    public:
		static void convert(std::string literal);
		

		//utils
		static bool isInteger(const std::string &literal);
		static bool isFloat(const std::string &literal);
		static bool isDouble(const std::string &literal);
};