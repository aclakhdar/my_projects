/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:14:59 by aclakhda          #+#    #+#             */
/*   Updated: 2025/07/23 11:23:56 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <iostream>
#include <string>

template <typename T>
void	swap(T &a, T &b)
{
	T	tmp;
	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T	min(T &a, T &b)
{
	T	return_value;
	if (a < b)
		return_value = a;
	else
		return_value = b;
	return return_value;
}

template <typename T>
T	max(T &a, T &b)
{
	T	return_value;
	if (a > b)
		return_value = a;
	else
		return_value = b;
	return return_value;
}
