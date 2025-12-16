/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:26:22 by aclakhda          #+#    #+#             */
/*   Updated: 2025/07/24 18:12:14 by aclakhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <stdlib.h>

template <typename T>
class	Array
{
	private :
		T				*arr;
		unsigned	int	arr_size;
	public :
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		~Array();
		Array & operator=(const Array &other);
		T	&operator[](unsigned int n);
		int	size() const;

		class	EmptyArray : public std::exception
		{
			const char *what() const throw();
		};

		class	IndexNotValid : public std::exception
		{
			const char *what() const throw();
		};
};

#include "Array.tpp"
