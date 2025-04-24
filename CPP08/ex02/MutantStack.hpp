/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:40:08 by yabejani          #+#    #+#             */
/*   Updated: 2025/04/24 15:57:53 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    private:

    public:
        MutantStack(){
        }
        MutantStack(const MutantStack &other) : std::stack<T>(other){
        }
        ~MutantStack(){    
        }

        MutantStack &operator=(const MutantStack& other){
            std::stack<T>::operator=(other);
            return *this;
        }
        
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        
        iterator begin(){
            return this->c.begin();
        }
        iterator end(){
            return this->c.end();
        }
};

// #ifndef MUTANTSTACK_HPP
// #define MUTANTSTACK_HPP

// #include <stack>

// template <typename T>
// class MutantStack : public std::stack<T> {
// public:
//     MutantStack() {}
//     MutantStack(const MutantStack& other) : std::stack<T>(other) {}
//     ~MutantStack() {}

//     MutantStack& operator=(const MutantStack& other) {
//         std::stack<T>::operator=(other);
//         return *this;
//     }

//     typedef typename std::stack<T>::container_type::iterator iterator;
//     typedef typename std::stack<T>::container_type::const_iterator const_iterator;

//     iterator begin() { return this->c.begin(); }
//     iterator end() { return this->c.end(); }

//     const_iterator begin() const { return this->c.begin(); }
//     const_iterator end() const { return this->c.end(); }
// };

// #endif
