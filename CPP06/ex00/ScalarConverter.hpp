/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:05:25 by yabejani          #+#    #+#             */
/*   Updated: 2025/02/04 17:31:18 by yabejani         ###   ########.fr       */
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
		ScalarConverter	&operator=(ScalarConverter &rhs);

		~ScalarConverter();

    public:
		static void convert(std::string const &literal);
};