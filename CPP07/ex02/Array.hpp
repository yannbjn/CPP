/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:27:40 by yabejani          #+#    #+#             */
/*   Updated: 2025/04/09 17:28:33 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include "Array.tpp"

#include <stdexcept>

template <typename T>
class Array {
private:
    T* _data;
    unsigned int _size;

public:
    Array();                            // Default constructor
    Array(unsigned int n);             // Constructor with size
    Array(Array const & other);        // Copy constructor
    Array & operator=(Array const & other); // Assignment
    ~Array();                           // Destructor

    T & operator[](unsigned int index);             // Access operator (modifiable)
    T const & operator[](unsigned int index) const; // Access operator (read-only)

    unsigned int size() const;
};

#include "Array.tpp" // Implémentation séparée dans .tpp

#endif
