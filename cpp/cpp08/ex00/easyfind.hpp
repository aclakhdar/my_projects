/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 19:21:54 by aclakhda          #+#    #+#             */
/*   Updated: 2025/08/05 17:08:05 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &c, int value)
{
	typename	T::iterator i = std::find(c.begin(), c.end(), value);
	if (i == c.end())
		throw std::runtime_error("value not found");
	return i;
}
