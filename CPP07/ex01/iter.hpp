/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:15:49 by yabejani          #+#    #+#             */
/*   Updated: 2025/04/10 17:04:07 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T>
void	iter(T* array, int length, void (*func)(T  &)){
	for (int i = 0; i < length; i++)
		func(array[i]);
}

template<typename T>
void	iter(const T* array, int length, void (*func)(const T &)){
	for (int i = 0; i < length; i++)
		func(array[i]);
}


