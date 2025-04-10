/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:27:40 by yabejani          #+#    #+#             */
/*   Updated: 2025/04/10 15:54:47 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include <stdexcept>
#include <iostream>

// template <typename T>
// class Array
// {
// private:
//     T* _data;
//     unsigned int _size;

// public:
//     template <typename T>
//     Array<T>::Array() : _data(NULL), _size(0){}

//     template <typename T>
//     Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n){}

//     template <typename T>
//     Array<T>::Array(Array const & other): _data(NULL), _size(0){}

//     template <typename T>
//     Array<T> &Arrayoperator=(Array const & other){
//         if (this != &other) {
//             delete[] _data;
//             _size = other._size;
//             _data = new T[_size];
//             for (unsigned int i = 0; i < _size; ++i)
//                 _data[i] = other._data[i];
//         }
//         return *this;
//     }

//     template <typename T>
//     Array<T>::~Array(){
//         delete[] _data;
//     }
    
//     Template <typename T>
//     T & Array<T>::operator[](unsigned int index){
//         if (index >= size)
//             throw std::out_of_range("Index out of bounds");
//         return _data[index];
//     }

//     template <typename T>
//     T const & Array<T>::operator[](unsigned int index) const{
//         if (index >= _size)
//             throw std::out_of_range("Index out of bounds");
//         return _data[index];
//     }

//     // template <typename T>
//     // unsigned int Array<T>::size() const{
//     //     return _size;
//     // }
//     unsigned size() const{
//         return this->_size;
//     }
// };


template <typename T>
class Array
{
private:
    T* _data;
    unsigned int _size;

public:
    Array() : _data(NULL), _size(0){}

    Array(unsigned int n) : _data(new T[n]()), _size(n){}

    Array(Array<T> const & other): _data(NULL), _size(0){}

    Array<T> &Arrayoperator=(Array<T> const &other){
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
    
    T & operator[](unsigned int index){
        if (index >= size)
            throw std::out_of_range("Index out of bounds");
        return _data[index];
    }

    T const & operator[](unsigned int index) const{
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return _data[index];
    }

    /
    // unsigned int Array<T>::size() const{
    //     return _size;
    // }
    unsigned size() const{
        return this->_size;
    }
};

