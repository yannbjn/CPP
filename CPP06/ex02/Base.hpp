/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:11:59 by yabejani          #+#    #+#             */
/*   Updated: 2025/04/07 19:07:46 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <ctime>
#include <exception>
#include <cstdlib>

class Base
{
	public:
		virtual ~Base();
};

class A: public Base{
	
};

class B: public Base{
	
};

class C: public Base{
	
};

Base*	generate(void);
void	identify(Base *p);
void	identify(Base &p);