/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:30:22 by yabejani          #+#    #+#             */
/*   Updated: 2025/04/24 18:47:48 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <map>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _rates;
    
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        ~BitcoinExchange();
        
        BitcoinExchange &operator=(const BitcoinExchange &rhs);
        
        void loadDB(const std::string &filename);
        void evaluateInput(const std::string &filename) const;
};
