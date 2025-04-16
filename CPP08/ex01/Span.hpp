/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:37:46 by frite             #+#    #+#             */
/*   Updated: 2025/04/16 17:06:09 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <stdexcept>
#include <algorithm>

class Span
{
    private:
        unsigned int _maxSize;
        std::vector<int> _numbers;
    
    public:
        Span();
        Span(unsigned int n);
        
        ~Span();

        void addNumber(int num);
        int shortestSpan() const;
        int longestSpan() const;

        class NotEnoughSpaceInSpanException : public std::exception{
            public:
                virtual const char *what() const throw(){
                    return ("Not enough space in Span!");
                }
                
        };

        class NotEnoughNumbersToFindASpanpanException : public std::exception{
            public:
                virtual const char *what() const throw(){
                    return ("Not enough numbers to find a span!");
                }
                
        };
        
        template <typename Iterator>
        void addRange(Iterator begin, Iterator end){
            if (_number.size() + std::distance(begin, end) > _maxSize)
                throw NotEnoughSpaceInSpanException();
            _numbers.insert(_numbers.end(), begin, end);
        }
};
