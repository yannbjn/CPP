/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:55:10 by frite             #+#    #+#             */
/*   Updated: 2025/04/16 15:55:26 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>

#include "easyfind.hpp"

int main(void)
{
    std::vector<int> intvec;
    
    intvec.push_back(1);
    intvec.push_back(2);
    intvec.push_back(3);
    intvec.push_back(42);
    intvec.push_back(6);

    
    std::list<int> intlst;

    intlst.push_back(10);
    intlst.push_back(11);
    intlst.push_back(12);
    intlst.push_back(42);
    intlst.push_back(14);
    

    //devrait marcher
    std::cout << "-----test 1------" << std::endl;
    try{
        std::vector<int>::iterator it1 = easyfind(intvec, 42);
        std::cout << "Found in vector: " << *it1 << std::endl;
    }
    catch (std::exception &e){
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    //ne devrait pas marcher
    std::cout << "-----test 2------" << std::endl;
    try{
        std::vector<int>::iterator it2 = easyfind(intvec, 5);
        std::cout << "Found in vector: " << *it2 << std::endl;
    }
    catch (std::exception &e){
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }


    //devrait marcher
    std::cout << "-----test 3------" << std::endl;
    try{
        std::list<int>::iterator it3 = easyfind(intlst, 42);
        std::cout << "Found in list: " << *it3 << std::endl;
    }
    catch (std::exception &e){
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }


    //ne devrait pas marcher
    std::cout << "-----test 4------" << std::endl;
    try{
        std::list<int>::iterator it4 = easyfind(intlst, 13);
        std::cout << "Found in list: " << *it4 << std::endl;
    }
    catch (std::exception &e){
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}

