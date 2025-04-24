/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:39:54 by yabejani          #+#    #+#             */
/*   Updated: 2025/04/24 17:27:33 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include <iostream>
#include <list>
#include <algorithm>

int main(void)
{
    std::cout << "Example with our mutant stack mstack :" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Last element added to mstack = " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size of mstack = " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    std::cout << "Contents of mstack : " << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
    
    std::cout << "Example with an other type of container, in this case a list :" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << "Last element added to lst = "<< lst.back() << std::endl;
    lst.pop_back();
    std::cout << "Size of lst = " << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    //[...]
    lst.push_back(0);
    
    std::cout << "Contents of lst :" << std::endl;
    for (std::list<int>::iterator lit = lst.begin(); lit != lst.end(); ++lit)
    {
        std::cout << *lit << std::endl;
    }
    return 0;
}

//int main()
//{
    // std::list<int> lst;
    // lst.push_back(5);
    // lst.push_back(17);
    // std::cout << lst.back() << std::endl;
    // lst.pop_back();
    // std::cout << lst.size() << std::endl;
    // lst.push_back(3);
    // lst.push_back(5);
    // lst.push_back(737);
    // //[...]
    // lst.push_back(0);
    
    // std::cout << "Contents of lst :" << std::endl;
    // for (std::list<int>::iterator lit = lst.begin(); lit != lst.end(); ++lit)
    // {
    //     std::cout << *lit << std::endl;
    // }
    // return 0;
//}
