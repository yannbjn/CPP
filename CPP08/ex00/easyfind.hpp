/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:55:24 by frite             #+#    #+#             */
/*   Updated: 2025/04/16 15:54:44 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>
#include <algorithm>


class ValueNotFoundException : public std::exception{
    public:
        virtual const char *what() const throw(){
            return ("Value not found!");
        }
        
};

template <typename T>
typename T::iterator easyfind(T& container, int value){
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw ValueNotFoundException();
    return it;
}

