/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 20:12:02 by yabejani          #+#    #+#             */
/*   Updated: 2024/09/13 20:14:45 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

bool ft_isdigit(const std::string &number) {
    for (std::string::size_type i = 0; i < number.size(); ++i) {
        char ch = number[i];
        if (!(ch >= '0' && ch <= '9')) {
            return false;
        }
    }
    return true;
}

#include <string>

int stringToInt(const std::string &str) {
    int result = 0;
    bool isNegative = false;

    std::string::size_type start = 0;
    if (str[0] == '-') {
        isNegative = true;
        start = 1;
    }
    for (std::string::size_type i = start; i < str.size(); ++i) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
        result = result * 10 + (str[i] - '0');
    }
    return isNegative ? -result : result;
}
