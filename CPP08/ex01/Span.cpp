/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:50:10 by frite             #+#    #+#             */
/*   Updated: 2025/04/16 17:22:10 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxSize(0){
    
}

Span::Span(unsigned int n) : _maxSize(n){
    
}

Span::~Span(){
    
}

void Span::addNumber(int num){
    if (_numbers.size() >= _maxSize)
        throw Span::NotEnoughSpaceInSpanException();
    _numbers.push_back(num);
}

int Span::shortestSpan() const{
    if (_numbers.size() < 2)
        throw Span::NotEnoughNumbersToFindASpanpanException();
    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());

    int minSpan = tmp[1] - tmp[0];
    for (size_t i = 1; i < tmp.size() - 1; ++i){
        int diff = tmp[i + 1] - tmp[i];
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

int Span::longestSpan() const{
    if (_numbers.size() < 2)
        throw Span::NotEnoughNumbersToFindASpanpanException();
    
    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());

    return max - min;
}

