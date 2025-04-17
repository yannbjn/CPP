/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:27:40 by yabejani          #+#    #+#             */
/*   Updated: 2025/04/17 15:08:55 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>
#include <iostream>


template <typename T>
class Array
{
private:
    T* _data;
    unsigned int _size;

public:
    Array() : _data(NULL), _size(0){}

    Array(unsigned int n) : _data(new T[n]()), _size(n){
        
    }

    Array(const Array &other): _size(other._size){
        _data = new T[_size];
        for (unsigned int i = 0; i < _size; ++i)
            _data[i] = other._data[i];
    }

    Array &operator=(const Array &other){
        if (this != &other) {
            delete[] _data;
            _size = other._size;
            _data = new T[_size];
            for (unsigned int i = 0; i < _size; ++i)
                _data[i] = other._data[i];
        }
        return *this;
    }

    ~Array(){
        delete[] _data;
    }
    
    T& operator[](unsigned int index){
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return _data[index];
    }

    const T& operator[](unsigned int index) const{
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return _data[index];
    }

    unsigned int size() const{
        return _size;
    }
};
