/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:18:28 by yabejani          #+#    #+#             */
/*   Updated: 2025/04/10 17:04:01 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "iter.hpp"

// template<typename T>
// void printElem(T &x){
// 	std::cout << x << std::endl;
// }

template<typename T>
void printElem(T& x){
	std::cout << x << std::endl;
}

template<typename T>
void minusss(T& x){
	x = x - 32;
}

int main(void){
	const char arr[] = {'b', 'o', 'n', 'j', 'o', 'u', 'r'};

	char arr1[] = {'b', 'o', 'n', 'j', 'o', 'u', 'r'};
	iter(arr1, 7, printElem);
	std::cout << "------------------" << std::endl;
	iter(arr1, 7, minusss);
	iter(arr, 7, printElem);
	int tab[] = {12, 23 , 345, 3, 42, 24};
	std::cout << "------------------" << std::endl;
	iter(arr1, 6, minusss);
}

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}
