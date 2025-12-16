/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:57:06 by aclakhda          #+#    #+#             */
/*   Updated: 2025/07/24 15:10:46 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template <typename T>
void	print(T const &smt)
{
	std::cout << smt << std::endl;
}

template <typename T, typename F>
void	iter(T *arr, size_t const size, F func)
{
	for (size_t i = 0; i < size; i++)
	{
		func(arr[i]);
	}
}

// template <typename T> hada example
// void	iter(T *arr, size_t const size, void (*f)(T &))
// {
// 	for (size_t i = 0; i < size; i++)
// 	{
// 		f(arr[i]);
// 	}
// }
