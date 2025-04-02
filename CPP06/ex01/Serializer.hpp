/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:11:29 by frite             #+#    #+#             */
/*   Updated: 2025/04/02 17:36:59 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iomanip>
#include <string>
#include <stdint.h>
#include <iostream>

typedef struct Data
{
    std::string name;
    int age;
    Data *next;
} Data;


class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer &src);
    
    public:
        ~Serializer();

        Serializer &operator=(const Serializer &rhs);

        static uintptr_t serialize(Data* ptr);
        static Data*    deserialize(uintptr_t raw);
};

//std::ostream	&operator<<(std::ostream &o, Data *a);